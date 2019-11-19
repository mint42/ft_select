/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_all_selected.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 07:46:22 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 08:03:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "screen.h"
#include "display.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>

static inline void		delete_selected(struct s_info *info, uint32_t arg)
{
	--info->n_active_args;
	info->args[info->args[arg].active_next].active_prev =
		info->args[arg].active_prev;
	info->args[info->args[arg].active_prev].active_next =
		info->args[arg].active_next;
	info->args[arg].delete_group_id = info->max_delete_group_id;
	info->args[arg].status = DELETED;
	if (arg == info->cursor_arg)
	{
		if (info->cursor_coord >= info->n_active_args)
		{
			--info->cursor_coord;
			info->cursor_arg = info->args[info->cursor_arg].active_prev;
		}
		else
			info->cursor_arg = info->args[info->cursor_arg].active_next;
	}
	else if (arg < info->cursor_arg)
		--info->cursor_coord;
	if (arg == info->starting_arg)
		info->starting_arg = info->args[info->starting_arg].active_next;
}

int						action_delete_all_selected(struct s_info *info)
{
	uint32_t	arg;
	uint32_t	i;

	if (info->n_selected_args)
		++(info->max_delete_group_id);
	else
		return (SUCCESS);
	if ((info->n_active_args - info->n_selected_args) == 0)
		return (BREAK);
	if (wipe_screen() == ERROR)
		return (ERROR);
	arg = info->starting_arg;
	i = info->n_active_args;
	while (i)
	{
		if (info->args[arg].status == SELECTED)
			delete_selected(info, arg);
		arg = info->args[arg].active_next;
		--i;
	}
	info->n_selected_args = 0;
	info->s_len = 0;
	if (display_screen(info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
