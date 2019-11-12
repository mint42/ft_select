/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:46:12 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/10 07:36:33 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "print.h"
#include "screen.h"
#include "struct_info.h"
#include "struct_term.h"
#include "ft_mem.h"
#include "ft_str.h"
#include <signal.h>
#include <stdlib.h>

static void		restore_and_exit(int sig)
{
	struct s_term	*term;
	struct s_info	*info;

	(void)sig;
	hold_term(&term, GET_TERM);
	hold_info(&info, GET_INFO);
	if (reset_screen(term) == ERROR)
		exit(ERROR);
	if (reset_term(term) == ERROR)
		exit(ERROR);
	ft_strdel(&(info->selected));
	ft_memdel((void **)&(info->args));
	print_error();
	exit(ERROR);
}

static void		resize(int sig)
{
	struct s_info	*info;

	(void)sig;
	hold_info(&info, GET_INFO);
	if (clear_screen(info) == ERROR)
		restore_and_exit(0);
	if (update_window_size(info) == ERROR)
		restore_and_exit(0);
	if (print_screen(info) == ERROR)
		restore_and_exit(0);
}

void			setup_signal_catching(void)
{
	signal(SIGWINCH, resize);
	signal(SIGSEGV, restore_and_exit);
	signal(SIGINT, restore_and_exit);
	signal(SIGABRT, restore_and_exit);
	signal(SIGILL, restore_and_exit);
	signal(SIGTERM, restore_and_exit);
	signal(SIGFPE, restore_and_exit);
}
