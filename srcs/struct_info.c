/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:01 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/04 22:33:14 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <ncurses.h>
#include <term.h>

int		setup_info(struct s_info *info, int argc, char **argv)
{
	info->max_arg_len = 0;
	if (setup_args(&(info->args), &(info->max_arg_len), argc, argv) == ERROR)
		return (ERROR);
	info->n_args = argc - 1;
	info->terminal_width = tgetnum("co");
	info->terminal_height = tgetnum("li");
	info->column_width = info->max_arg_len + COLUMN_PADDING;
	info->n_columns = info->terminal_width / info->column_width;
	info->n_rows = info->n_args / info->n_columns;
	if (info->n_args % info->n_columns)
		++(info->n_rows);
	info->cursor_coordinate = 0;
	return (SUCCESS);
}
