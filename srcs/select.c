/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:43:52 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/10 06:55:10 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "actions.h"
#include "struct_info.h"
#include "struct_term.h"
#include "print.h"
#include "ft_mem.h"
#include <unistd.h>

static int		execute_action(uint32_t index, struct s_info *info)
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
		action_search_mode,
	};

	if (action_table[index](info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static int		get_action(uint64_t buff)
{
	int		index;

	index = 0;
	while  (index < TOTAL_ACTION_CODES)
	{
		if (g_action_codes[index] == buff)
			return (index / 2);
		++index;
	}
	return (-1);
}

int				do_selecting(int argc, char **argv, struct s_term *term)
{
	struct s_info	info;
	uint64_t		buff;
	uint32_t		index;

	(void)term;
	if (setup_info(&info, argc, argv) == ERROR)
		return (ERROR);
	print_screen(&info);
	while (42)
	{
		buff = 0;
		read(STDIN_FILENO, &buff, 4);
		index = get_action(buff);
		execute_action(index, &info);
	}
	ft_memdel((void **)&(info.args));
	return (SUCCESS);
}
