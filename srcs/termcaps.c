/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 01:23:11 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/01 01:40:00 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include <ncurses.h>
#include <stdlib.h>
#include <term.h>

int		setup_termcaps(void)
{
	char	*termtype;
	char	*term_buffer;
	int		error;	

	termtype = getenv("TERM");
	if (!termtype)
		return (print_error(TERM_NOT_SPECIFIED));
	term_buffer = 0;
	error = tgetent(term_buffer, termtype);
	if (error < 0)
		return (print_error(BAD_TERMCAP_ACCESS));
	else if (error == 0)
		return(print_error(TERM_NOT_DEFINED));
	return (SUCCESS);
}
