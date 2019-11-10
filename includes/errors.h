/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 00:07:56 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/09 17:48:29 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define SUCCESS 0
# define ERROR 1

enum	e_error_code
{
	E_MALLOC = -1,
	E_USAGE,
	E_TERM_NOT_SPECIFIED,
	E_TERM_NOT_DEFINED,
	E_TCGETATTR,
	E_TCSETATTR,
	E_TGETENT,
	E_TGETSTR,
	TOTAL_ERRORS,
};

int		set_error(enum e_error_code ec);
void	print_error(void);

#endif
