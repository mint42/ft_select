/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:45:02 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/05 04:57:27 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "ft_put.h"
#include <unistd.h>

static enum e_error_code	g_errno;

int		set_error(enum e_error_code ec)
{
	g_errno = ec;
	return (ERROR);
}

void	print_error(void)
{
	const char *const errors[TOTAL_ERRORS] = {
		"$TERM environment variable not set",
		"$TERM environment variable not recognized by termcaps",
		"tgetent() failed",
		"tcgetattr() failed",
		"tcsetattr() failed",
	};

	if (g_errno > -1)
		ft_putendl_fd(errors[g_errno], STDERR_FILENO);
}
