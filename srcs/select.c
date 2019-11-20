/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:43:52 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 04:04:18 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "config.h"
#include "actions.h"
#include "struct_info.h"
#include "display.h"
#include "ft_mem.h"
#include <stdint.h>
#include <unistd.h>

static int		execute_action(int32_t index, struct s_info *info)
{
	static int		(*action_table[TOTAL_ACTIONS])() = {
		action_left,
		action_down,
		action_up,
		action_right,
		action_select,
		action_select_all,
		action_delete,
		action_delete_all_selected,
		action_restore,
		action_undo,
		action_return,
		action_quit,
		action_help_mode,
	};

	return (action_table[index](info));
}

static int		get_secondary_action(uint64_t buff)
{
	uint32_t				i;
	static const uint64_t	secondary_action_codes[TOTAL_ACTIONS] = {
		K_SEC_LEFT,
		K_SEC_DOWN,
		K_SEC_UP,
		K_SEC_RIGHT,
		K_SEC_SELECT,
		K_SEC_SELECT_ALL,
		K_SEC_DELETE,
		K_SEC_DELETE_ALL,
		K_SEC_RESORE,
		K_SEC_UNDO,
		K_SEC_RETURN,
		K_SEC_QUIT,
		K_SEC_HELP,
	};

	i = 0;
	while (i < TOTAL_ACTIONS)
	{
		if (secondary_action_codes[i] == buff)
			return (i);
		++i;
	}
	return (-1);
}

static int		get_primary_action(uint64_t buff)
{
	uint32_t				i;
	static const uint64_t	primary_action_codes[TOTAL_ACTIONS] = {
		K_PRI_LEFT,
		K_PRI_DOWN,
		K_PRI_UP,
		K_PRI_RIGHT,
		K_PRI_SELECT,
		K_PRI_SELECT_ALL,
		K_PRI_DELETE,
		K_PRI_DELETE_ALL,
		K_PRI_RESORE,
		K_PRI_UNDO,
		K_PRI_RETURN,
		K_PRI_QUIT,
		K_PRI_HELP,
	};

	i = 0;
	while (i < TOTAL_ACTIONS)
	{
		if (primary_action_codes[i] == buff)
			return (i);
		++i;
	}
	return (-1);
}

int				do_selecting(struct s_info *info)
{
	uint64_t		buff;
	int32_t			index;

	if (display_screen(info) == ERROR)
		return (ERROR);
	buff = 0;
	while (read(STDIN_FILENO, &buff, 4))
	{
		if (info->screen_too_small == TRUE)
			continue ;
		index = get_primary_action(buff);
		if (index == -1)
			index = get_secondary_action(buff);
		if (index >= 0)
		{
			if (execute_action(index, info) == BREAK)
				break ;
		}
		buff = 0;
	}
	return (SUCCESS);
}
