/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:01 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/15 09:02:01 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "print.h"
#include "config.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <curses.h>
#include <term.h>
#include <sys/ioctl.h>
#include <unistd.h>

void	hold_info(struct s_info **info, uint8_t action)
{
	static struct s_info	*held_info;

	if (action == SET_INFO)
		held_info = *info;
	else if (action == GET_INFO)
		*info = held_info;
}

#include "ft_printf.h"
int		update_window_size(struct s_info *info)
{
	struct winsize	window;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &window) == -1)
		return (set_error(E_IOCTL));
	if ((window.ws_col - ((BOX_PADDING * 2) - 17) <= 0) || (window.ws_row - ((BOX_PADDING * 2) - 10) <= 0))
	{
		ft_printfd(STDIN_FILENO, "1", 1);
		if (print_resize(info) == ERROR)
			return (ERROR);
	}
	info->term_width = window.ws_col;
	info->term_height = window.ws_row;
	info->screen_width = window.ws_col - (BOX_PADDING * 2) - 6;
	info->screen_height = window.ws_row - (BOX_PADDING * 2) - 10;
	info->column_width = info->max_arg_len + COLUMN_PADDING;
	info->n_columns = info->screen_width / info->column_width;
	if (info->n_active_args < info->n_columns)
		info->n_columns = info->n_active_args;
	if (info->n_columns == 0)
	{
		ft_printfd(STDIN_FILENO, "2", 1);
		if (print_resize(info) == ERROR)
			return (ERROR);
	}
	info->n_rows = info->n_active_args / info->n_columns;
	if (info->n_active_args % info->n_columns)
		++info->n_rows;
	if (info->n_rows > info->screen_height)
	{
		ft_printfd(STDIN_FILENO, "3", 1);
		if (print_resize(info) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int		setup_info(struct s_info *info, int argc, char **argv)
{
	hold_info(&info, SET_INFO);
	info->mode = SELECT_MODE;
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
