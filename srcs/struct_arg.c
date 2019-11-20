/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:32:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 07:37:35 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_arg.h"
#include "struct_info.h"
#include "ft_mem.h"
#include "ft_str.h"
#include <stdint.h>

static void		setup_arg(struct s_arg *arg, uint32_t n_active_args,
						char **argv, uint32_t i)
{
	arg->name = argv[i + 1];
	arg->len = ft_strlen(arg->name);
	arg->status = UNSELECTED;
	if (i == 0)
		arg->active_prev = n_active_args - 1;
	else
		arg->active_prev = i - 1;
	if (i == n_active_args - 1)
		arg->active_next = 0;
	else
		arg->active_next = i + 1;
	arg->delete_group_id = 0;
}

int				setup_args(struct s_info *info, char **argv)
{
	uint32_t	i;

	info->args = (struct s_arg *)ft_memalloc(sizeof(struct s_arg) *
		info->n_active_args);
	if (!info->args)
		return (set_error(E_MALLOC));
	i = 0;
	while (i < info->n_active_args)
	{
		setup_arg(&(info->args[i]), info->n_active_args, argv, i);
		if (info->args[i].len > info->max_arg_len)
			info->max_arg_len = info->args[i].len;
		++i;
	}
	return (SUCCESS);
}
