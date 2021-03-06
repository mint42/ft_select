/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 07:46:25 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 07:46:51 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "display.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>

int		action_down(struct s_info *info)
{
	uint32_t	prev_cursor_arg;
	uint32_t	prev_cursor_coord;
	uint32_t	i;

	if (info->n_active_args == 1)
		return (SUCCESS);
	prev_cursor_arg = info->cursor_arg;
	prev_cursor_coord = info->cursor_coord;
	i = info->n_columns;
	if (info->cursor_coord >= info->n_active_args - info->n_columns)
	{
		i = (info->cursor_coord + 1) % info->n_columns;
		info->cursor_arg = info->starting_arg;
		info->cursor_coord = 0;
	}
	while (i > 0)
	{
		info->cursor_arg = info->args[info->cursor_arg].active_next;
		++info->cursor_coord;
		--i;
	}
	display_arg(&(info->args[prev_cursor_arg]), prev_cursor_coord, info);
	display_arg(&(info->args[info->cursor_arg]), info->cursor_coord, info);
	return (SUCCESS);
}
