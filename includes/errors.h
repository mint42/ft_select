/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 04:09:11 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 04:09:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define BREAK (-1)
# define SUCCESS 0
# define ERROR 1

# define SET_ERROR 1
# define GET_ERROR 2

enum	e_error_code
{
	E_MALLOC = 1,
	E_TERM_NOT_SPECIFIED,
	E_TERM_NOT_DEFINED,
	E_TCGETATTR,
	E_TCSETATTR,
	E_TGETENT,
	E_TGETSTR,
	E_IOCTL,
	E_READ,
	TOTAL_ERRORS,
};

int		set_error(enum e_error_code ec);
void	print_error(void);

#endif
