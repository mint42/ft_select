/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:43:52 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/10 05:14:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_arg.h"
#include "struct_info.h"
#include "struct_term.h"
#include "tc.h"
#include "ft_printf.h"
#include "ft_mem.h"
#include <unistd.h>

void	print_string(struct s_arg *arg, uint32_t coord, struct s_info *info)
{
	uint32_t	x_pos;
	uint32_t	y_pos;
	char		*esc_seq;

	esc_seq = 0;
	x_pos = (coord % info->n_columns) * (info->column_width + COLUMN_PADDING);
	y_pos = coord / info->n_columns;
	tc_move_cur(x_pos, y_pos);
	if (arg->status == SELECTED && coord == info->cursor_coord)
		esc_seq = "\e[7;4m";
	else if (arg->status == SELECTED)
		esc_seq = "\e[7m";
	else if (coord == info->cursor_coord)
		esc_seq = "\e[4m";
	if (esc_seq)
	{
		ft_printfd(STDIN_FILENO, "%s%-*s\e[0m", esc_seq, COLUMN_PADDING,
			arg->name);
	}
	else
		ft_printfd(STDIN_FILENO, "%-*s", COLUMN_PADDING, arg->name);
}

void	print_screen(struct s_info *info)
{
	uint32_t	coord;
	uint32_t	arg;

	arg = info->starting_arg;
	coord = 0;
	while (coord < info->n_active_args)
	{
		print_string(&((info->args)[arg]), coord, info);
		arg = (info->args)[arg].active_next;
		++coord;
	}
}

int		do_selecting(int argc, char **argv, struct s_term *term)
{
	struct s_info	info;

	(void)term;
	if (setup_info(&info, argc, argv) == ERROR)
		return (ERROR);
	print_screen(&info);
	while (42)
	{
		;
	}
	ft_memdel((void **)&(info.args));
	return (SUCCESS);
}
