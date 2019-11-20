/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:01 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 08:24:57 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "config.h"
#include "box_drawing.h"
#include "help.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <curses.h>
#include <term.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <unistd.h>

void			hold_info(struct s_info **info, uint8_t action)
{
	static struct s_info	*held_info;

	if (action == SET_INFO)
		held_info = *info;
	else if (action == GET_INFO)
		*info = held_info;
}

void			find_new_max_arg_len(struct s_info *info)
{
	uint32_t	i;
	uint32_t	arg;
	uint32_t	new_max_arg_len;

	i = 0;
	arg = info->starting_arg;
	new_max_arg_len = 0;
	while (i < info->n_active_args)
	{
		if (info->args[arg].len > new_max_arg_len)
			new_max_arg_len = info->args[arg].len;
		arg = info->args[arg].active_next;
		++i;
	}
	info->max_arg_len = new_max_arg_len;
}

static void		update_window_info(struct s_info *info)
{
	info->screen_width = info->term_width - (TOTAL_PAD_WIDTH * 2);
	info->screen_height = info->term_height - (TOTAL_PAD_HEIGHT * 2);
	info->screen_too_small = FALSE;
	info->column_width = info->max_arg_len + COLUMN_PADDING;
	info->n_columns = info->screen_width / info->column_width;
	if (info->n_columns == 0)
	{
		info->column_width = info->screen_width;
		info->n_columns = 1;
	}
	else if (info->n_active_args < info->n_columns)
		info->n_columns = info->n_active_args;
	info->n_rows = info->n_active_args / info->n_columns;
	if (info->n_active_args % info->n_columns)
		++info->n_rows;
}

int				update_window_size(struct s_info *info)
{
	struct winsize	window;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &window) == -1)
		return (set_error(E_IOCTL));
	info->term_width = window.ws_col;
	info->term_height = window.ws_row;
	if ((((int32_t)(info->term_width - TOTAL_MIN_WIDTH)) <= 0) ||
			(((int32_t)(info->term_height - TOTAL_MIN_HEIGHT)) <= 0))
	{
		info->screen_too_small = TRUE;
		return (SUCCESS);
	}
	update_window_info(info);
	if (((int32_t)(info->screen_height - info->n_rows)) < 0)
		info->screen_too_small = TRUE;
	return (SUCCESS);
}

int				setup_info(struct s_info *info, int argc, char **argv)
{
	hold_info(&info, SET_INFO);
	info->screen_too_small = FALSE;
	info->screen_mode = SELECT_MODE;
	info->max_arg_len = 0;
	info->args = 0;
	info->n_args = argc - 1;
	info->n_active_args = argc - 1;
	info->starting_arg = 0;
	if (setup_args(info, argv) == ERROR)
		return (ERROR);
	info->max_delete_group_id = 0;
	info->cursor_arg = 0;
	info->cursor_coord = 0;
	info->selected = 0;
	info->s_len = 0;
	info->n_selected_args = 0;
	if (update_window_size(info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
