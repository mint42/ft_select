/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:21:31 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/09 21:56:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "ft_put.h"
#include <curses.h>
#include <term.h>
#include <unistd.h>

static int	ft_putnbr_stdin(int n)
{
	return (write(STDIN_FILENO, &n, 1));
}

static int	put_tc(char *id)
{
	char	*termcap_string;

	termcap_string = tgetstr(id, 0);
	if (!termcap_string)
		return (set_error(E_TGETSTR));
	tputs(termcap_string, 1, ft_putnbr_stdin);
	return (SUCCESS);
}

int			setup_screen(void)
{
	if (put_tc("ti") == ERROR)
		return (ERROR);
	if (put_tc("vi") == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int			reset_screen(void)
{
	if (put_tc("te") == ERROR)
		return (ERROR);
	if (put_tc("ve") == ERROR)
		return (ERROR);
	return (SUCCESS);
}
