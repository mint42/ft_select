/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:21:31 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 06:13:29 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_info.h"
#include "display.h"
#include "tc.h"

int		wipe_screen(void)
{
	if (tc_put("cl") == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int		update_screen(struct s_info *info)
{
	if (update_window_size(info) == ERROR)
		return (ERROR);
	if (wipe_screen() == ERROR)
		return (ERROR);
	if (display_screen(info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int		setup_screen(void)
{
	if (tc_put("ti") == ERROR)
	{
		if (wipe_screen() == ERROR)
			return (ERROR);
	}
	if (tc_put("vi") == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int		restore_screen(void)
{
	if (tc_put("te") == ERROR)
	{
		if (wipe_screen() == ERROR)
			return (ERROR);
	}
	if (tc_put("ve") == ERROR)
		return (ERROR);
	return (SUCCESS);
}
