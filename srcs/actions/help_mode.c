/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 07:46:27 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/15 07:26:15 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "actions.h"
#include "screen.h"
#include "print.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>
#include <unistd.h>

int		action_help_mode(struct s_info *info)
{
	uint64_t	buff;

	if (clear_screen(info) == ERROR)
		return (ERROR);
	info->mode = HELP_MODE;
	if (print_help_screen(info) == ERROR)
		return (ERROR);
	buff = 0;
	while (buff != K_QUIT_HELP_MODE)
	{
		if (read(STDIN_FILENO, &buff, 1) == -1)
			return (set_error(E_READ));
	}
	if (clear_screen(info) == ERROR)
		return (ERROR);
	info->mode = SELECT_MODE;
	if (print_screen(info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
