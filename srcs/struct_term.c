/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:07 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 08:10:45 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_term.h"
#include "ft_mem.h"
#include <curses.h>
#include <term.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>

void		hold_term(struct s_term **term, uint8_t action)
{
	static struct s_term	*held_term;

	if (action == SET_TERM)
		held_term = *term;
	else if (action == GET_TERM)
		*term = held_term;
}

static int	get_term_buffer(struct s_term *term)
{
	char	*term_type;
	int		error_code;

	term_type = getenv("TERM");
	if (!term_type || !*term_type)
		return (set_error(E_TERM_NOT_SPECIFIED));
	error_code = tgetent(term->term_buffer, term_type);
	if (error_code < 0)
		return (set_error(E_TGETENT));
	else if (error_code == 0)
		return (set_error(E_TERM_NOT_DEFINED));
	return (SUCCESS);
}

static int	get_term_settings(struct s_term *term)
{
	if (tcgetattr(STDIN_FILENO, &term->old_settings) != 0)
		return (set_error(E_TCGETATTR));
	hold_term(&term, SET_TERM);
	ft_memcpy(&term->new_settings, &term->old_settings, sizeof(struct termios));
	term->new_settings.c_lflag = term->new_settings.c_lflag & ~(ICANON | ECHO);
	term->new_settings.c_cc[VMIN] = 1;
	term->new_settings.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &term->new_settings))
		return (set_error(E_TCSETATTR));
	return (SUCCESS);
}

int			setup_term(struct s_term *term)
{
	hold_term(&term, SET_TERM);
	if (get_term_buffer(term) == ERROR)
		return (ERROR);
	if (get_term_settings(term) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int			restore_term(struct s_term *term)
{
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &term->old_settings) != 0)
		return (set_error(E_TCGETATTR));
	return (0);
}
