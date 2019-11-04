/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 01:23:11 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/01 02:17:33 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_term.h"
#include <ncurses.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <termios.h>

static int	get_term_buffer(struct s_term *term)
{
	char	*term_type;
	int		error_code;

	term_type = getenv("TERM");
	if (!term_type)
		return (print_error(E_TERM_NOT_SPECIFIED));
	error_code = tgetent(term->term_buffer, term_type);
	if (error_code < 0)
		return (print_error(E_BAD_TERMCAP_ACCESS));
	else if (error_code == 0)
		return (print_error(E_TERM_NOT_DEFINED));
	return (SUCCESS);
}

static int	get_term_settings(struct s_term *term)
{
	(void)term;
	return (SUCCESS);
}

int			setup_terminal(struct s_term *term)
{
	term->term_buffer = 0;
	if (get_term_buffer(term) == ERROR)
		return (ERROR);
	if (get_term_settings(term) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int		reset_terminal(struct s_term *term)
{
	(void)term;
	return (SUCCESS);
}
