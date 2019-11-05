/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:46:12 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/05 05:05:57 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_term.h"
#include <signal.h>
#include <stdlib.h>

static void		restore_and_exit(int sig)
{
	(void)sig;
	reset_term();
	exit(ERROR);
}

void			setup_signal_catching(void)
{
	signal(SIGSEGV, restore_and_exit);
	signal(SIGINT, restore_and_exit);
	signal(SIGABRT, restore_and_exit);
	signal(SIGILL, restore_and_exit);
	signal(SIGTERM, restore_and_exit);
	signal(SIGFPE, restore_and_exit);
}
