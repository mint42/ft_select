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
	MALLOC = -1,
	TERM_NOT_SPECIFIED,
	TERM_NOT_DEFINED,
	BAD_TERMCAP_ACCESS,
	TOTAL_ERRORS,
};

int		print_error(enum e_error_code ec);

#endif
