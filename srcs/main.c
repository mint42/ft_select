/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 03:07:05 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/31 23:43:52 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
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

/*
**	static void		setup_termcaps()
**	{
**		char			*termtype;
**	
**		termtype = getenv("TERM");
**		if (!termtype)
**			return (print_error(TERM_NOT_SPECIFIED));
**		if (tgetent()
**	}
*/

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
