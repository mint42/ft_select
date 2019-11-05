/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:32:44 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/04 22:32:45 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "select.h"
#include "struct_term.h"

int				main(int argc, char **argv)
{
	struct s_term	term;

	if (argc < 2)
		return (print_error(E_USAGE));
	if (setup_terminal(&term) == ERROR)
		return (ERROR);
	if (select(argc, argv, &term))
		return (ERROR);
	if (reset_terminal(&term) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
