/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 07:46:36 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 23:51:38 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "config.h"
#include "struct_info.h"
#include "struct_arg.h"
#include "ft_str.h"
#include <stdint.h>

static inline void		copy_arg(struct s_info *info, uint32_t arg,
								uint32_t *offset)
{
	ft_strncpy(info->selected + *offset, info->args[arg].name,
			info->args[arg].len);
	*offset = *offset + info->args[arg].len + OUTPUT_PADDING_LEN;
}

int						action_return(struct s_info *info)
{
	uint32_t	i;
	uint32_t	arg;
	uint32_t	offset;

	if (info->n_selected_args == 0)
		return (BREAK);
	info->s_len = info->s_len + ((info->n_selected_args - 1) *
			OUTPUT_PADDING_LEN) + 1;
	info->selected = ft_strinit(OUTPUT_PADDING_CHAR, info->s_len);
	if (!info->selected)
		return (set_error(E_MALLOC));
	arg = info->starting_arg;
	offset = 0;
	i = 0;
	while (i < info->n_active_args)
	{
		if (info->args[arg].status == SELECTED)
			copy_arg(info, arg, &offset);
		arg = info->args[arg].active_next;
		++i;
	}
	info->selected[info->s_len - 1] = '\n';
	return (BREAK);
}
