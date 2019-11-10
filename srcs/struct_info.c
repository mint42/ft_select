/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:01 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/10 03:39:22 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <ncurses.h>
#include <term.h>

void	hold_info(struct s_info **info, uint8_t action)
{
	static struct s_info	*held_info;

	if (action == SET_INFO)
		held_info = *info;
	else if (action == GET_INFO)
		*info = held_info;
}

void	update_terminal_size(void)
{
	struct s_info	*info;
	uint32_t		terminal_width;
	uint32_t		terminal_height;

	hold_info(&info, GET_INFO);
	terminal_width = tgetnum("co");
	terminal_height = tgetnum("li");
	if (info->max_arg_len > terminal_width)
	{
		info->column_width = terminal_width;
		info->n_columns = 1;
		info->n_rows = info->n_active_args;
	}
	else
	{
		info->column_width = info->max_arg_len;
		info->n_columns = terminal_width / (info->column_width +
			COLUMN_PADDING);
		info->n_rows = info->n_active_args / info->n_columns;
		if (info->n_active_args % info->n_columns)
			++(info->n_rows);
	}
}

int		setup_info(struct s_info *info, int argc, char **argv)
{
	hold_info(&info, SET_INFO);
	info->max_arg_len = 0;
	if (setup_args(&(info->args), &(info->max_arg_len), argc, argv) == ERROR)
		return (ERROR);
	info->n_active_args = argc - 1;
	info->starting_arg = 0;
	info->cursor_arg = 0;
	info->cursor_coord = 0;
	update_terminal_size();
	return (SUCCESS);
}
