/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 07:46:43 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 07:46:51 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "print.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>

int		action_select_all(struct s_info *info)
{
	uint32_t	arg;
	uint32_t	coord;

	arg = info->starting_arg;
	coord = 0;
	while (coord < info->n_active_args)
	{
		if (info->args[arg].status == UNSELECTED)
		{
			info->args[arg].status = SELECTED;
			info->s_len = info->s_len + info->args[arg].len;
			print_string(&(info->args[arg]), coord, info);
		}
		arg = info->args[arg].active_next;
		++coord;
	}
	info->n_selected_args = info->n_active_args;
	return (SUCCESS);
}
