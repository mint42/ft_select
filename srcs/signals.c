/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:46:12 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 07:47:40 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "display.h"
#include "actions.h"
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
	if (restore_screen() == ERROR)
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
	if (update_screen(info) == ERROR)
		restore_and_exit(0);
}

static void		run_in_background(int sig)
{
	struct s_term	*term;

	(void)sig;
	hold_term(&term, GET_TERM);
	if (restore_screen() == ERROR)
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
	if (setup_screen() == ERROR)
		restore_and_exit(0);
	if (info->screen_mode == HELP_MODE)
	{
		if (action_help_mode(info) == ERROR)
			restore_and_exit(ERROR);
	}
	if (do_selecting(info) == ERROR)
		restore_and_exit(ERROR);
}

void			setup_signal_catching(void)
{
	signal(SIGINT, restore_and_exit);
	signal(SIGTERM, restore_and_exit);
	signal(SIGHUP, restore_and_exit);
	signal(SIGTSTP, run_in_background);
	signal(SIGCONT, run_in_foreground);
	signal(SIGWINCH, resize);
}

void			restore_signal_catching(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
	signal(SIGHUP, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGCONT, SIG_DFL);
	signal(SIGWINCH, SIG_DFL);
}
