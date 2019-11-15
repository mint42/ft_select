/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 06:05:09 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/15 07:21:33 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "select.h"
#include "struct_info.h"
#include "config.h"
#include "box_drawing.h"
#include "tc.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

static int		print_details(struct s_info *info, uint8_t mode)
{
	if (tc_move_cur(BOX_PADDING + 3, BOX_PADDING + 1) == ERROR)
		return (ERROR);
	write(STDIN_FILENO, "ft_select", 9);
	if (tc_move_cur(info->term_width - BOX_PADDING - 6, BOX_PADDING + 1) == ERROR)
		return (ERROR);
	if (mode == HELP_MODE)
	{
		write(STDIN_FILENO, "[?]", 3);
		if (tc_move_cur(info->term_width - BOX_PADDING - 14, info->term_height - BOX_PADDING - 2) == ERROR)
			return (ERROR);
		write(STDIN_FILENO, "\'q\' to exit", 11);
	}
	else
	{
		write(STDIN_FILENO, "[ ]", 3);
		if (tc_move_cur(info->term_width - BOX_PADDING - 14, info->term_height - BOX_PADDING - 2) == ERROR)
			return (ERROR);
		write(STDIN_FILENO, "\'?\' to help", 11);
	}
	return (SUCCESS);
}


static void		draw_line(struct s_info *info, wchar_t start_char, wchar_t middle_char, wchar_t end_char)
{
	uint32_t	i;

	i = 0;
	ft_printfd(STDIN_FILENO, "%lc", start_char);
	while (i < info->term_width - (BOX_PADDING * 2) - 2)
	{
		ft_printfd(STDIN_FILENO, "%lc", middle_char);
		++i;
	}
	ft_printfd(STDIN_FILENO, "%lc", end_char);
}

static int		draw_bottom(struct s_info *info)
{
	if (tc_move_cur(BOX_PADDING, info->term_height - BOX_PADDING - 3) == ERROR)
		return (ERROR);
	draw_line(info, L'├', L'─', L'┤');
	if (tc_move_cur(BOX_PADDING, info->term_height - BOX_PADDING - 2) == ERROR)
		return (ERROR);
	draw_line(info, L'│', ' ', L'│');
	if (tc_move_cur(BOX_PADDING, info->term_height - BOX_PADDING - 1) == ERROR)
		return (ERROR);
	draw_line(info, L'└', L'─', L'┘');
	return (SUCCESS);
}

static int		draw_top(struct s_info *info)
{
	if (tc_move_cur(BOX_PADDING, BOX_PADDING) == ERROR)
		return (ERROR);
	draw_line(info, L'┌', L'─', L'┐');
	if (tc_move_cur(BOX_PADDING, BOX_PADDING + 1) == ERROR)
		return (ERROR);
	draw_line(info, L'│', ' ', L'│');
	if (tc_move_cur(BOX_PADDING, BOX_PADDING + 2) == ERROR)
		return (ERROR);
	draw_line(info, L'├', L'─', L'┤');
	return (SUCCESS);
}

int				draw_box(struct s_info *info, uint8_t mode)
{
	uint32_t	i;

	if (draw_top(info) == ERROR)
		return (ERROR);
	i = 3;
	while (i < info->term_height - BOX_PADDING - 3)
	{
		if (tc_move_cur(BOX_PADDING, BOX_PADDING + i))
			return (ERROR);
		draw_line(info, L'│', ' ', L'│');
		++i;
	}
	if (draw_bottom(info) == ERROR)
		return (ERROR);
	print_details(info, mode);
	return (SUCCESS);
}
