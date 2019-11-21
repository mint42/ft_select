/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 05:22:27 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 23:41:04 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "box_drawing.h"
#include "config.h"
#include "struct_arg.h"
#include "struct_info.h"
#include "tc.h"
#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>

void			display_arg(struct s_arg *arg, uint32_t coord,
						struct s_info *info)
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
		ft_printfd(STDIN_FILENO, "%s", esc_seq);
	if (arg->len > info->screen_width)
	{
		ft_printfd(STDIN_FILENO, "%-.*s%s", info->screen_width -
				TRUNCATE_STRING_LEN, arg->name, TRUNCATE_STRING);
	}
	else
		ft_printfd(STDIN_FILENO, "%-s", arg->name);
	if (esc_seq)
		write(STDIN_FILENO, "\e[0m", 4);
}

static int		display_select_screen(struct s_info *info)
{
	uint32_t	coord;
	uint32_t	arg;

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

static int		display_help_screen(void)
{
	uint32_t					i;
	static const char *const	help_menu[TOTAL_ACTIONS] = {
		"Left Arrow ... Move left",
		"Down Arrow ... Move down",
		"Up Arrow ..... Move up",
		"Right Arrow .. Move right",
		"Bksp/Delete .. Delete",
		"Space ........ Select/Deselect",
		"D ............ Delete all selected",
		"a ............ Select all",
		"u ............ Undo",
		"r ............ Restore to default",
		"Enter ........ Return selected items",
		"q ............ Quit without saving",
		"? ............ Help Mode",
	};

	i = 0;
	while (i < TOTAL_ACTIONS)
	{
		if (tc_move_cur(TOTAL_PAD_WIDTH, TOTAL_PAD_HEIGHT + i) == ERROR)
			return (ERROR);
		ft_printfd(STDIN_FILENO, "%s", help_menu[i++]);
	}
	return (SUCCESS);
}

static int		display_too_small_screen(void)
{
	if (tc_move_cur(0, 0) == ERROR)
		return (ERROR);
	write(STDIN_FILENO, "screen too smol :(", 18);
	return (SUCCESS);
}

int				display_screen(struct s_info *info)
{
	int		error_code;

	error_code = 0;
	if (info->screen_too_small == TRUE)
		error_code = display_too_small_screen();
	else
	{
		if (info->screen_mode == HELP_MODE)
		{
			if (draw_box(info, HELP_MODE) == ERROR)
				return (ERROR);
			error_code = display_help_screen();
		}
		else
		{
			if (draw_box(info, SELECT_MODE) == ERROR)
				return (ERROR);
			error_code = display_select_screen(info);
		}
	}
	return (error_code);
}
