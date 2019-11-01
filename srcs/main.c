/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 03:07:05 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/01 01:36:34 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "select.h"
#include "termcaps.h"
#include "struct_format.h"
#include "struct_item.h"
#include "ft_mem.h"
#include "ft_printf.h"
#include <stdint.h>

static void		do_selecting(struct s_item *items, int argc)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		ft_printf("%s\n", (items[i]).name);
		++i;
	}
}

int				main(int argc, char **argv)
{
	struct s_item	*items;
	struct s_format	format;

	if (argc < 2)
		return (0);
	items = (struct s_item *)ft_memalloc(sizeof(struct s_item) * argc - 1);
	if (!items)
		return (print_error(MALLOC));
	init_format(&format);
	init_items(items, &format, argc - 1, argv);
	if (setup_termcaps() == ERROR)
		return (ERROR);
	do_selecting(items, argc - 1);
	ft_memdel((void **)&items);
	return (SUCCESS);
}
