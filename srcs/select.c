/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:43:52 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 08:01:48 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "actions.h"
#include "struct_info.h"
#include "struct_term.h"
#include "print.h"
#include "ft_mem.h"
#include <unistd.h>

static int		execute_action(int32_t index, struct s_info *info)
{
	static int		(*action_table[])() = {
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

static int		get_action(uint64_t buff)
{
	int32_t		index;

	index = 0;
	while (index < TOTAL_ACTION_CODES)
	{
		if (g_action_codes[index] == buff)
			return (index / 2);
		++index;
	}
	return (-1);
}

int				do_selecting(struct s_info *info)
{
	uint64_t		buff;
	int32_t			index;

	print_screen(info);
	while (42)
	{
		buff = 0;
		read(STDIN_FILENO, &buff, 4);
		index = get_action(buff);
		if (index >= 0)
			if (execute_action(index, info) == BREAK)
				break ;
	}
	return (SUCCESS);
}
