/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 07:46:19 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 08:03:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "screen.h"
#include "display.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>

static inline void		update_cursor_position(struct s_info *info)
{
	if (info->cursor_arg == info->starting_arg)
		info->starting_arg = info->args[info->cursor_arg].active_next;
	if (info->cursor_coord == info->n_active_args)
	{
		--info->cursor_coord;
		info->cursor_arg = info->args[info->cursor_arg].active_prev;
	}
	else
		info->cursor_arg = info->args[info->cursor_arg].active_next;
}

int						action_delete(struct s_info *info)
{
	--(info->n_active_args);
	if (info->n_active_args == 0)
		return (BREAK);
	if (wipe_screen() == ERROR)
		return (ERROR);
	if (info->args[info->cursor_arg].status == SELECTED)
	{
		info->s_len = info->s_len - info->args[info->cursor_arg].len;
		--info->n_selected_args;
	}
	info->args[info->args[info->cursor_arg].active_next].active_prev =
		info->args[info->cursor_arg].active_prev;
	info->args[info->args[info->cursor_arg].active_prev].active_next =
		info->args[info->cursor_arg].active_next;
	++(info->max_delete_group_id);
	info->args[info->cursor_arg].status = DELETED;
	info->args[info->cursor_arg].delete_group_id = info->max_delete_group_id;
	update_cursor_position(info);
	find_new_max_arg_len(info);
	if (update_window_size(info) == ERROR)
		return (ERROR);
	if (display_screen(info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
