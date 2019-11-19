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
#include "screen.h"
#include "help.h"
#include "display.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>
#include <unistd.h>

int		action_help_mode(struct s_info *info)
{
	uint64_t	buff;

	if (wipe_screen() == ERROR)
		return (ERROR);
	info->screen_mode = HELP_MODE;
	if (display_help_screen(info) == ERROR)
		return (ERROR);
	buff = 0;
	while (buff != K_QUIT_HELP_MODE)
	{
		if (read(STDIN_FILENO, &buff, 1) == -1)
			return (set_error(E_READ));
	}
	if (wipe_screen() == ERROR)
		return (ERROR);
	info->screen_mode = SELECT_MODE;
	if (display_screen(info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
