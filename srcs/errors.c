/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:45:02 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 07:50:39 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "ft_put.h"
#include <stdint.h>
#include <unistd.h>

static void	hold_error(enum e_error_code *ec, uint8_t action)
{
	static enum e_error_code	held_ec;

	if (action == SET_ERROR)
		held_ec = *ec;
	else if (action == GET_ERROR)
		*ec = held_ec;
}

int			set_error(enum e_error_code ec)
{
	hold_error(&ec, SET_ERROR);
	return (ERROR);
}

void		print_error(void)
{
	enum e_error_code	ec;
	const char *const	errors[TOTAL_ERRORS] = {
		0,
		0,
		"$TERM environment variable not set",
		"$TERM environment variable not recognized by termcaps",
		"tcgetattr() failed",
		"tcsetattr() failed",
		"tgetent() failed",
		"tgetstr() failed",
		"ioctl() failed",
		"read() failed",
		"Insufficient columns",
		"minimum term size exceeded",
	};

	hold_error(&ec, GET_ERROR);
	if (ec > 1)
	{
		ft_putstr("ft_select: error: ");
		ft_putendl_fd(errors[ec], STDERR_FILENO);
	}
}
