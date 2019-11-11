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
#include "keys.h"
#include "struct_info.h"
#include "struct_term.h"
#include "print.h"
#include "ft_mem.h"
#include <unistd.h>

int		parse_buff(char buff, struct s_info *info)
{
	static void		(*key_table[])() = {
		['h'] = h_key,
		['j'] = j_key,
		['k'] = k_key,
		['l'] = l_key,
		['a'] = a_key,
		['d'] = d_key,
		['r'] = r_key,
		['u'] = u_key,
		['q'] = q_key,
		['?'] = questn_key,
		['/'] = fslash_key,
		[' '] = space_key,
	};

	key_table[(uint8_t)buff](info);
	return (SUCCESS);
}

int		do_selecting(int argc, char **argv, struct s_term *term)
{
	struct s_info	info;
	char			buff;

	(void)term;
	if (setup_info(&info, argc, argv) == ERROR)
		return (ERROR);
	print_screen(&info);
	while (42)
	{
		read(STDIN_FILENO, &buff, 1);
		parse_buff(buff, &info);
	}
	ft_memdel((void **)&(info.args));
	return (SUCCESS);
}
