/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:45:02 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/01 01:33:32 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "ft_put.h"
#include <unistd.h>

int		print_error(enum e_error_code ec)
{
	const char *const errors[TOTAL_ERRORS] = {
		"./ft_select [args]",
		"$TERM environment variable not set",
		"$TERM environment variable not recognized by termcaps",
		"bad access to termcaps library"
	};

	if (ec > -1)
		ft_putendl_fd(errors[ec], STDERR_FILENO);
	return (ERROR);
}
