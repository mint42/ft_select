/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:07 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/09 22:22:07 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_term.h"
#include "ft_mem.h"
#include <ncurses.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <termios.h>
#include <unistd.h>

static void	hold_settings(struct termios *settings, uint8_t action)
{
	static struct termios	hold_settings;

	if (action == SET_SETTINGS)
		ft_memcpy(&hold_settings, settings, sizeof(struct termios));
	else if (action == GET_SETTINGS)
		*settings = hold_settings;
}

static int	get_term_buffer(struct s_term *term)
{
	char	*term_type;
	int		error_code;

	term_type = getenv("TERM");
	if (!term_type)
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
	struct termios	old_settings;

	if (tcgetattr(STDIN_FILENO, &old_settings) != 0)
		return (set_error(E_TCGETATTR));
	hold_settings(&old_settings, SET_SETTINGS);
	ft_memcpy(&term->new_settings, &old_settings, sizeof(struct termios));
	term->new_settings.c_lflag = term->new_settings.c_lflag & ~(ICANON | ECHO);
	term->new_settings.c_cc[VMIN] = 1;
	term->new_settings.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &term->new_settings))
		return (set_error(E_TCSETATTR));
	return (SUCCESS);
}

int			setup_term(struct s_term *term)
{
	term->term_buffer = 0;
	if (get_term_buffer(term) == ERROR)
		return (ERROR);
	if (get_term_settings(term) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int			reset_term(void)
{
	struct termios	settings;

	hold_settings(&settings, GET_SETTINGS);
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &settings) != 0)
		return (set_error(E_TCGETATTR));
	return (0);
}
