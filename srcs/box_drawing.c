/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 06:05:09 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/16 20:14:36 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_info.h"
#include "config.h"
#include "box_drawing.h"
#include "tc.h"
#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>

static int		print_details(struct s_info *info, uint8_t mode)
{
	if (tc_move_cur(TOTAL_PAD_WIDTH, OUTER_PAD_HEIGHT + 1) == ERROR)
		return (ERROR);
	write(STDIN_FILENO, "ft_select", 9);
	if (tc_move_cur(info->term_width - (TOTAL_PAD_WIDTH + 3), OUTER_PAD_HEIGHT + 1) == ERROR)
		return (ERROR);
	if (mode == HELP_MODE)
		write(STDIN_FILENO, "[?]", 3);
	else
		write(STDIN_FILENO, "[ ]", 3);
	if (tc_move_cur(info->term_width - (TOTAL_PAD_WIDTH + 11), info->term_height - (OUTER_PAD_HEIGHT - 2)) == ERROR)
		return (ERROR);
	if (mode == HELP_MODE)
		write(STDIN_FILENO, "\'q\' to quit", 11);
	else
		write(STDIN_FILENO, "\'?\' to help", 11);
	return (SUCCESS);
}

static void		draw_line(struct s_info *info, wchar_t start_char,
					wchar_t middle_char, wchar_t end_char)
{
	uint32_t	i;

	i = 0;
	ft_printfd(STDIN_FILENO, "%lc", start_char);
	while (i < info->term_width - (OUTER_PAD_WIDTH * 2) - (BUILT_IN_WIDTH * 2))
	{
		ft_printfd(STDIN_FILENO, "%lc", middle_char);
		++i;
	}
	ft_printfd(STDIN_FILENO, "%lc", end_char);
}

static int		draw_bottom(struct s_info *info)
{
	if (tc_move_cur(OUTER_PAD_WIDTH, info->term_height - OUTER_PAD_HEIGHT - 3) == ERROR)
		return (ERROR);
	draw_line(info, L'├', L'─', L'┤');
	if (tc_move_cur(OUTER_PAD_WIDTH, info->term_height - OUTER_PAD_HEIGHT - 2) == ERROR)
		return (ERROR);
	draw_line(info, L'│', ' ', L'│');
	if (tc_move_cur(OUTER_PAD_WIDTH, info->term_height - OUTER_PAD_HEIGHT - 1) == ERROR)
		return (ERROR);
	draw_line(info, L'└', L'─', L'┘');
	return (SUCCESS);
}

static int		draw_top(struct s_info *info)
{
	if (tc_move_cur(OUTER_PAD_WIDTH, OUTER_PAD_HEIGHT) == ERROR)
		return (ERROR);
	draw_line(info, L'┌', L'─', L'┐');
	if (tc_move_cur(OUTER_PAD_WIDTH, OUTER_PAD_HEIGHT + 1) == ERROR)
		return (ERROR);
	draw_line(info, L'│', ' ', L'│');
	if (tc_move_cur(OUTER_PAD_WIDTH, OUTER_PAD_HEIGHT + 2) == ERROR)
		return (ERROR);
	draw_line(info, L'├', L'─', L'┤');
	return (SUCCESS);
}

int				draw_box(struct s_info *info, uint8_t mode)
{
	uint32_t	i;

	if (draw_top(info) == ERROR)
		return (ERROR);
	i = OUTER_PAD_HEIGHT + BUILT_IN_HEIGHT;
	while (i < info->term_height - (OUTER_PAD_HEIGHT + BUILT_IN_HEIGHT))
	{
		if (tc_move_cur(OUTER_PAD_WIDTH, i) == ERROR)
			return (ERROR);
		draw_line(info, L'│', ' ', L'│');
		++i;
	}
	if (draw_bottom(info) == ERROR)
		return (ERROR);
	print_details(info, mode);
	return (SUCCESS);
}
