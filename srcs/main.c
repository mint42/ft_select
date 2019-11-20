/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:32:44 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 08:26:43 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "screen.h"
#include "select.h"
#include "signals.h"
#include "struct_info.h"
#include "struct_term.h"
#include "ft_mem.h"
#include "ft_str.h"
#include <unistd.h>

static int		ft_select(int argc, char **argv)
{
	struct s_term	term;
	struct s_info	info;
	int				error_code;

	setup_signal_catching();
	if (setup_term(&term) == ERROR)
		return (ERROR);
	if (setup_screen() == ERROR)
		return (ERROR);
	if (setup_info(&info, argc, argv) == ERROR)
		return (ERROR);
	error_code = do_selecting(&info);
	if (restore_screen() == ERROR)
		return (ERROR);
	if (restore_term(&term) == ERROR)
		return (ERROR);
	write(STDOUT_FILENO, info.selected, info.s_len);
	ft_strdel(&(info.selected));
	ft_memdel((void **)&(info.args));
	restore_signal_catching();
	return (error_code);
}

int				main(int argc, char **argv)
{
	int				error_code;

	if (argc < 2)
	{
		write(STDERR_FILENO, "usage: ft_select [args]\n", 24);
		return (ERROR);
	}
	error_code = ft_select(argc, argv);
	if (error_code == ERROR)
		print_error();
	return (error_code);
}
