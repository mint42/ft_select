/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 05:22:27 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/15 09:01:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "box_drawing.h"
#include "screen.h"
#include "config.h"
#include "struct_arg.h"
#include "struct_info.h"
#include "tc.h"
#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>

void	print_string(struct s_arg *arg, uint32_t coord, struct s_info *info)
{
	uint32_t	x_pos;
	uint32_t	y_pos;
	char		*esc_seq;

	esc_seq = 0;
	x_pos = ((coord % info->n_columns) * info->column_width) + BOX_PADDING + 3;
	y_pos = (coord / info->n_columns) + BOX_PADDING + 4;
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

int		print_screen(struct s_info *info)
{
	uint32_t	coord;
	uint32_t	arg;

	if (draw_box(info, SELECT_MODE) == ERROR)
		return (ERROR);
	arg = info->starting_arg;
	coord = 0;
	while (coord < info->n_active_args)
	{
		print_string(&(info->args[arg]), coord, info);
		arg = info->args[arg].active_next;
		++coord;
	}
	return (SUCCESS);
}

int		print_help_screen(struct s_info *info)
{
	if (draw_box(info, HELP_MODE) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int		print_resize(struct s_info *info)
{
//	if (clear_screen(info) == ERROR)
//		return (ERROR);
	(void)info;
	write(STDIN_FILENO, "screen too smol :(", 18);
	return (SUCCESS);
}

/*
**	write(fd, "  ┌───────────────────────────────────────────────┐  \n", 200);
**	write(fd, "  │  ft_select                                [?] │  \n", 200);
**	write(fd, "  ├───────────────────────────────────────────────┤  \n", 200);
**	write(fd, "  │                                             ┬ │  \n", 200);
**	write(fd, "  │  h, left  - move left                       │ │  \n", 200);
**	write(fd, "  │  j, down  - move down                       │ │  \n", 200);
**	write(fd, "  │  k, up    - move up                         │ │  \n", 200);
**	write(fd, "  │  l, right - move right                      │ │  \n", 200);
**	write(fd, "  │  space    - select/deselect                 │ │  \n", 200);
**	write(fd, "  │  a        - select all                      │ │  \n", 200);
**	write(fd, "  │  d        - deselect all                    │ │  \n", 200);
**	write(fd, "  │  x        - delete                          │ │  \n", 200);
**	write(fd, "  │  u        - undo                            │ │  \n", 200);
**	write(fd, "  │  r        - restore to default              │ │  \n", 200);
**	write(fd, "  │  q, esc   - quit without saving             │ │  \n", 200);
**	write(fd, "  │  /        - finder                          │ │  \n", 200);
**	write(fd, "  │  ?        - help                            │ │  \n", 200);
**	write(fd, "  │                                             ┴ │  \n", 200);
**	write(fd, "  ├───────────────────────────────────────────────┤  \n", 200);
**	write(fd, "  │                                     Esc exit  │  \n", 200);
**	write(fd, "  └───────────────────────────────────────────────┘  \n", 200);k}
*/
