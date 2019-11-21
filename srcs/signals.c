/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 23:44:51 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 23:54:13 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_functions.h"
#include <signal.h>

void		setup_signal_catching(void)
{
	signal(SIGINT, restore_and_exit);
	signal(SIGTERM, restore_and_exit);
	signal(SIGHUP, restore_and_exit);
	signal(SIGTSTP, run_in_background);
	signal(SIGCONT, run_in_foreground);
	signal(SIGWINCH, resize);
}

void		restore_signal_catching(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
	signal(SIGHUP, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGCONT, SIG_DFL);
	signal(SIGWINCH, SIG_DFL);
}
