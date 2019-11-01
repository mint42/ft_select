/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_items.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:31:25 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/31 23:44:04 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "struct_format.h"
#include "struct_item.h"
#include "ft_str.h"

void	init_items(struct s_item *items, struct s_format *format,
			int argc, char **argv)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		(items[i]).name = argv[i + 1];
		(items[i]).len = ft_strlen((items[i]).name);
		(items[i]).status = ACTIVE;
		if (i == 0)
			(items[i]).active_prev = argc - 1;
		else
			(items[i]).active_prev = i - 1;
		if (i == argc - 1)
			(items[i]).active_next = 0;
		else
			(items[i]).active_next = i + 1;
		(items[i]).finder_prev = 0;
		(items[i]).finder_next = 0;
		if ((items[i]).len > format->max_name_len)
			format->max_name_len = (items[i]).len;
		++i;
	}
}
