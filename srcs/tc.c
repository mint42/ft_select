/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 02:39:11 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/10 03:35:14 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include <curses.h>
#include <term.h>
#include <stdint.h>
#include <unistd.h>

static int	ft_putchar_stdin(int n)
{
	return (write(STDIN_FILENO, &n, 1));
}

int			tc_move_cur(uint32_t x_pos, uint32_t y_pos)
{
	char	*termcap_string;

	termcap_string = tgetstr("cm", 0);
	if (!termcap_string)
		return (set_error(E_TGETSTR));
	termcap_string = tgoto(termcap_string, x_pos, y_pos);
	tputs(termcap_string, 1, ft_putchar_stdin);
	return (SUCCESS);
}

int			tc_put(char *tc_id)
{
	char	*termcap_string;

	termcap_string = tgetstr(tc_id, 0);
	if (!termcap_string)
		return (set_error(E_TGETSTR));
	tputs(termcap_string, 1, ft_putchar_stdin);
	return (SUCCESS);
}
