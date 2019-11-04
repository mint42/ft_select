/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 00:07:56 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/01 01:36:04 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define SUCCESS 0
# define ERROR 1

enum	e_error_code
{
	E_MALLOC = -1,
	E_NO_ARGS,
	E_TERM_NOT_SPECIFIED,
	E_TERM_NOT_DEFINED,
	E_BAD_TERMCAP_ACCESS,
	TOTAL_ERRORS,
};

int		print_error(enum e_error_code ec);

#endif
