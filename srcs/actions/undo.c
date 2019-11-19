/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 07:46:46 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 08:03:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "screen.h"
#include "display.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>

static inline void		undo_deleted(struct s_info *info, uint32_t arg)
{
	info->args[info->args[arg].active_prev].active_next = arg;
	info->args[info->args[arg].active_next].active_prev = arg;
	info->args[arg].status = UNSELECTED;
	info->args[arg].delete_group_id = 0;
	if (arg < info->starting_arg)
		info->starting_arg = arg;
	if (arg < info->cursor_arg)
		++info->cursor_coord;
	++info->n_active_args;
}

int						action_undo(struct s_info *info)
{
	uint32_t	arg;

	if (!info->max_delete_group_id)
		return (SUCCESS);
	if (wipe_screen() == ERROR)
		return (ERROR);
	arg = 0;
	while (arg < info->n_args)
	{
		if (info->args[arg].status == DELETED &&
				info->args[arg].delete_group_id == info->max_delete_group_id)
		{
			undo_deleted(info, arg);
		}
		++arg;
	}
	--info->max_delete_group_id;
	if (display_screen(info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
