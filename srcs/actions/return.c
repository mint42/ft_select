/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 07:46:36 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 07:46:51 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "actions.h"
#include "struct_info.h"
#include "struct_arg.h"
#include "ft_str.h"
#include <stdint.h>

int		action_return(struct s_info *info)
{
	uint32_t	i;
	uint32_t	arg;
	uint32_t	offset;

	if (info->n_selected_args == 0)
		return (BREAK);
	info->selected = ft_strinit(' ', info->s_len + info->n_selected_args - 1);
	if (!info->selected)
		return (set_error(E_MALLOC));
	i = 0;
	arg = info->starting_arg;
	offset = 0;
	while (i < info->n_active_args)
	{
		if (info->args[arg].status == SELECTED)
		{
			ft_strncpy(info->selected + offset, info->args[arg].name,
				info->args[arg].len);
			offset = offset + info->args[arg].len + 1;
		}
		arg = info->args[arg].active_next;
		++i;
	}
	return (BREAK);
}
