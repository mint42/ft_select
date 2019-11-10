/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:21:31 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/09 19:48:48 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "ft_put.h"
#include <ncurses.h>
#include <term.h>
#include <unistd.h>

static int	ft_putnbr_stdin(int n)
{
	return (write(STDIN_FILENO, &n, 1));
}

int			setup_screen(void)
{
	char	*termcap_string;

	termcap_string = tgetstr("ti", 0);
	if (!termcap_string)
		return (set_error(E_TGETSTR));
	tputs(termcap_string, 1, ft_putnbr_stdin);
	termcap_string = tgetstr("vi", 0);
	if (!termcap_string)
		return (set_error(E_TGETSTR));
	tputs(termcap_string, 1, ft_putnbr_stdin);
	termcap_string = tgetstr("cl", 0);
	if (!termcap_string)
		return (set_error(E_TGETSTR));
	tputs(termcap_string, 1, ft_putnbr_stdin);
	return (SUCCESS);
}

int			reset_screen(void)
{
	char	*termcap_string;

	termcap_string = tgetstr("te", 0);
	if (!termcap_string)
		return (set_error(E_TGETSTR));
	tputs(termcap_string, 1, ft_putnbr_stdin);
	termcap_string = tgetstr("ve", 0);
	if (!termcap_string)
		return (set_error(E_TGETSTR));
	tputs(termcap_string, 1, ft_putnbr_stdin);
	return (SUCCESS);
}
