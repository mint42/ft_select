/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 03:07:05 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/28 15:00:51 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_printf.h"
#include "ft_str.h"
#include <stdint.h>

#define ACTIVE 0
#define INACTIVE 1
#define SELECTED 2

struct			s_format
{
	uint32_t	term_width;
	uint32_t	term_height;
	uint32_t	max_name_len;
	uint32_t	col_width;
	uint8_t		columns;
	uint8_t		rows;
	uint8_t		cursor_position;
};

struct			s_item
{
	char		*name;
	uint32_t	len;
	uint8_t		status;
	uint32_t	active_prev;
	uint32_t	active_next;
	uint32_t	finder_prev;
	uint32_t	finder_next;
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

static void		init_format(struct s_format *format)
{
	format->term_width = 0;
	format->term_height = 0;
	format->col_width = 0;
}

static void		init_items(struct s_item *items, struct s_format *format, int argc, char **argv)
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
		if ((items[i]).len > format->max_len)
			format->max_len = (items[i]).len;
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
		return (0);
	init_format(&format);
	init_items(items, &format, argc - 1, argv);
	do_selecting(items, argc - 1);
	ft_memdel((void **)&items);
}
