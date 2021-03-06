/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 07:46:40 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 08:02:25 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "display.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>

static inline void	select_arg(struct s_info *info)
{
	info->args[info->cursor_arg].status = SELECTED;
	info->s_len = info->s_len + info->args[info->cursor_arg].len;
	++info->n_selected_args;
}

static inline void	deselect_arg(struct s_info *info)
{
	info->args[info->cursor_arg].status = UNSELECTED;
	info->s_len = info->s_len - info->args[info->cursor_arg].len;
	--info->n_selected_args;
}

int					action_select(struct s_info *info)
{
	uint32_t	prev_cursor_arg;
	uint32_t	prev_cursor_coord;

	if (info->args[info->cursor_arg].status == UNSELECTED)
		select_arg(info);
	else
		deselect_arg(info);
	prev_cursor_arg = info->cursor_arg;
	prev_cursor_coord = info->cursor_coord;
	info->cursor_arg = info->args[info->cursor_arg].active_next;
	if (prev_cursor_arg >= info->cursor_arg)
		info->cursor_coord = 0;
	else
		++(info->cursor_coord);
	display_arg(&(info->args[prev_cursor_arg]), prev_cursor_coord, info);
	display_arg(&(info->args[info->cursor_arg]), info->cursor_coord, info);
	return (SUCCESS);
}
