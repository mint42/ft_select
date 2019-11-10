/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:32:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/10 02:30:41 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_arg.h"
#include "struct_info.h"
#include "ft_mem.h"
#include "ft_str.h"
#include <stdint.h>

static void		setup_arg(struct s_arg *args, int argc, char **argv, int i)
{
	(args[i]).name = argv[i + 1];
	(args[i]).len = ft_strlen((args[i]).name);
	(args[i]).status = ACTIVE;
	if (i == 0)
		(args[i]).active_prev = argc - 1;
	else
		(args[i]).active_prev = i - 1;
	if (i == argc - 1)
		(args[i]).active_next = 0;
	else
		(args[i]).active_next = i + 1;
	(args)[i].finder_prev = 0;
	(args)[i].finder_next = 0;
	(args)[i].inactive_group_id = 0;
}

int				setup_args(struct s_arg **args, uint32_t *max_arg_len, int argc,
					char **argv)
{
	int		i;

	*args = (struct s_arg *)ft_memalloc(sizeof(struct s_arg) * argc);
	if (!*args)
		return (set_error(E_MALLOC));
	i = 0;
	while (i < argc)
	{
		setup_arg(*args, argc, argv, i);
		if (((*args)[i]).len > *max_arg_len)
			*max_arg_len = ((*args)[i]).len;
		++i;
	}
	return (SUCCESS);
}
