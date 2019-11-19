/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:01 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/16 20:12:56 by rreedy           ###   ########.fr       */
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

void	hold_info(struct s_info **info, uint8_t action)
{
	static struct s_info	*held_info;

	if (action == SET_INFO)
		held_info = *info;
	else if (action == GET_INFO)
		*info = held_info;
}

int		update_window_size(struct s_info *info)
{
	struct winsize	window;
	uint32_t		screen_width;
	uint32_t		screen_height;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &window) == -1)
		return (set_error(E_IOCTL));
	info->term_width = window.ws_col;
	info->term_height = window.ws_row;
	if ((((int)(info->term_width - ((TOTAL_PAD_WIDTH * 2) + HELP_MENU_WIDTH))) <= 0) || (((int)(info->term_height - ((TOTAL_PAD_HEIGHT * 2) + HELP_MENU_HEIGHT))) <= 0))
	{
		info->screen_too_small = TRUE;
		return (SUCCESS);
	}
	info->screen_too_small = FALSE;
	screen_width = info->term_width - (TOTAL_PAD_WIDTH * 2);
	screen_height = info->term_height - (TOTAL_PAD_HEIGHT * 2);
	info->truncate = FALSE;
	info->column_width = info->max_arg_len + COLUMN_PADDING;
	info->n_columns = screen_width / info->column_width;
	if (info->n_columns == 0)
	{
		info->column_width = screen_width;
		info->truncate = TRUE;
		info->n_columns = 1;
	}
	else if (info->n_active_args < info->n_columns)
		info->n_columns = info->n_active_args;
	info->n_rows = info->n_active_args / info->n_columns;
	if (info->n_active_args % info->n_columns)
		++info->n_rows;
	info->n_pages = screen_height / info->n_rows;
	if (screen_height % info->n_rows)
		++info->n_pages;
	info->cursor_page = info->n_active_args / info->n_pages;
	return (SUCCESS);
}

int		setup_info(struct s_info *info, int argc, char **argv)
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
