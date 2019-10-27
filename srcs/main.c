/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 03:07:05 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/27 03:48:44 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_printf.h"
#include <stdint.h>

#define ACTIVE 0
#define INACTIVE 1
#define SELECTED 2

struct			s_item
{
	char		*name;
	uint8_t		status;
	uint8_t		active_prev;
	uint8_t		active_next;
	uint8_t		finder_prev;
	uint8_t		finder_next;
};

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

static void		init_items(struct s_item *items, int argc, char **argv)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		(items[i]).name = argv[i + 1];
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
		++i;
	}
}

int				main(int argc, char **argv)
{
	struct s_item	*items;

	if (argc < 2)
		return (0);
	items = (struct s_item *)ft_memalloc(sizeof(struct s_item) * argc - 1);
	if (!items)
		return (0);
	init_items(items, argc - 1, argv);
	do_selecting(items, argc - 1);
	ft_memdel((void **)&items);
}
