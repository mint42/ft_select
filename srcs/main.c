/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:32:44 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/05 01:36:08 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "select.h"
#include "struct_term.h"
#include <unistd.h>

int				main(int argc, char **argv)
{
	int				error_code;

	if (argc < 2)
	{
		write(STDERR_FILENO, "./ft_select [args]", 18);
		return (ERROR);
	}
	error_code = ft_select(argc, argv);
	if (error_code == ERROR)
		print_error();
	return (error_code);
}
