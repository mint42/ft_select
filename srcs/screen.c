/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:21:31 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 08:08:54 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "tc.h"

int		wipe_screen(void)
{
	if (tc_put("cl") == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int		setup_screen(void)
{
	if (tc_put("ti") == ERROR)
		return (ERROR);
	if (tc_put("vi") == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int		restore_screen(void)
{
	if (tc_put("te") == ERROR)
		return (ERROR);
	if (tc_put("ve") == ERROR)
		return (ERROR);
	return (SUCCESS);
}
