/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 07:46:34 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 06:17:00 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "screen.h"
#include "display.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>

static void		restore_arg(struct s_info *info, uint32_t arg)
{
	info->args[arg].status = UNSELECTED;
	if (arg == 0)
		info->args[arg].active_prev = info->n_active_args - 1;
	else
		info->args[arg].active_prev = arg - 1;
	if (arg == info->n_active_args - 1)
		info->args[arg].active_next = 0;
	else
		info->args[arg].active_next = arg + 1;
	info->args[arg].delete_group_id = 0;
}

int				action_restore(struct s_info *info)
{
	uint32_t	arg;

	info->starting_arg = 0;
	info->cursor_arg = info->starting_arg;
	info->cursor_coord = 0;
	info->n_active_args = info->n_args;
	info->max_delete_group_id = 0;
	info->n_selected_args = 0;
	info->s_len = 0;
	arg = info->starting_arg;
	while (arg < info->n_active_args)
	{
		restore_arg(info, arg);
		++arg;
	}
	find_new_max_arg_len(info);
	if (update_screen(info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
