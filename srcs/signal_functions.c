/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 23:28:13 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 23:37:28 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "screen.h"
#include "select.h"
#include "struct_info.h"
#include "struct_term.h"
#include "ft_mem.h"
#include "ft_str.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

void		restore_and_exit(int sig)
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

void		resize(int sig)
{
	struct s_info	*info;

	(void)sig;
	hold_info(&info, GET_INFO);
	if (update_screen(info) == ERROR)
		restore_and_exit(0);
}

void		run_in_background(int sig)
{
	struct s_term	*term;

	(void)sig;
	hold_term(&term, GET_TERM);
	if (restore_screen() == ERROR)
		restore_and_exit(ERROR);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

void		run_in_foreground(int sig)
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
