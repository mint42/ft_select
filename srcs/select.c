/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:43:52 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/10 06:55:10 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_info.h"
#include "struct_term.h"
#include "print.h"
#include "ft_mem.h"

int		do_selecting(int argc, char **argv, struct s_term *term)
{
	struct s_info	info;

	(void)term;
	if (setup_info(&info, argc, argv) == ERROR)
		return (ERROR);
	print_screen(&info);
	while (42)
	{
		;
	}
	ft_memdel((void **)&(info.args));
	return (SUCCESS);
}
