/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 05:22:27 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/16 20:12:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "box_drawing.h"
#include "config.h"
#include "help.h"
#include "struct_arg.h"
#include "struct_info.h"
#include "tc.h"
#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>

void		display_arg(struct s_arg *arg, uint32_t coord, struct s_info *info)
{
	uint32_t	x_pos;
	uint32_t	y_pos;
	char		*esc_seq;

	esc_seq = 0;
	x_pos = ((coord % info->n_columns) * info->column_width) + TOTAL_PAD_WIDTH;
	y_pos = (coord / info->n_columns) + TOTAL_PAD_HEIGHT;
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

int			display_screen(struct s_info *info)
{
	uint32_t	coord;
	uint32_t	arg;

	if (draw_box(info, SELECT_MODE) == ERROR)
		return (ERROR);
	arg = info->starting_arg;
	coord = 0;
	while (coord < info->n_active_args)
	{
		display_arg(&(info->args[arg]), coord, info);
		arg = info->args[arg].active_next;
		++coord;
	}
	return (SUCCESS);
}

int			display_help_screen(struct s_info *info)
{
	uint32_t					i;
	static const char * const	help_menu[TOTAL_ACTIONS] = {
		"left arrow ... Move left",
		"down arrow ... Move down",
		"up arrow ..... Move up",
		"right arrow .. Move right",
		"space ........ Select/Deselect",
		"a ............ Select all",
		"Backspace .... Delete",
		"D ............ Delete all",
		"u ............ Undo",
		"r ............ Restore to default",
		"Enter ........ Return selected items",
		"q ............ Quit without saving",
		"? ............ Help Mode",
	};

	if (draw_box(info, HELP_MODE) == ERROR)
		return (ERROR);
	i = 0;
	while (i < TOTAL_ACTIONS)
	{
		if (tc_move_cur(TOTAL_PAD_WIDTH, TOTAL_PAD_HEIGHT + i) == ERROR)
			return (ERROR);
		ft_printfd(STDIN_FILENO, "%s", help_menu[i]);
		++i;
	}
	return (SUCCESS);
}
