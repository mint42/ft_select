/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:46:12 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/15 09:53:59 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "print.h"
#include "screen.h"
#include "select.h"
#include "struct_info.h"
#include "struct_term.h"
#include "ft_mem.h"
#include "ft_str.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

static void		restore_and_exit(int sig)
{
	struct s_term	*term;
	struct s_info	*info;

	(void)sig;
	hold_term(&term, GET_TERM);
	hold_info(&info, GET_INFO);
	ft_strdel(&(info->selected));
	ft_memdel((void **)&(info->args));
	if (restore_screen(term) == ERROR)
		exit(ERROR);
	if (restore_term(term) == ERROR)
		exit(ERROR);
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
	if (info->mode == SELECT_MODE)
	{
		if (print_screen(info) == ERROR)
			restore_and_exit(0);
	}
	else
	{
		if (print_help_screen(info) == ERROR)
			restore_and_exit(0);
	}
}

static void		run_in_background(int sig)
{
	struct s_term	*term;

	(void)sig;
	hold_term(&term, GET_TERM);
	if (restore_screen(term) == ERROR)
		restore_and_exit(ERROR);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

static void		run_in_foreground(int sig)
{
	struct s_info	*info;
	struct s_term	*term;

	(void)sig;
	hold_term(&term, GET_TERM);
	hold_info(&info, GET_INFO);
	if (setup_term(term) == ERROR)
		restore_and_exit(0);
	if (setup_screen(info) == ERROR)
		restore_and_exit(0);
	if (info->mode == HELP_MODE)
	{
		if (print_help_screen(info) == ERROR)
			restore_and_exit(ERROR);
	}
	if (do_selecting(info) == ERROR)
		restore_and_exit(ERROR);
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
	signal(SIGTSTP, run_in_background);
	signal(SIGCONT, run_in_foreground);
}
