#include "errors.h"
#include "screen.h"
#include "print.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>

int		action_undo(struct s_info *info)
{
	uint32_t	arg;

	if (clear_screen() == ERROR)
		return (ERROR);
	arg = 0;
	while (arg < info->n_args)
	{
		if (info->args[arg].status == DELETED &&
				info->args[arg].delete_group_id == info->max_delete_group_id)
		{
			info->args[info->args[arg].active_prev].active_next = arg;
			info->args[info->args[arg].active_next].active_prev = arg;
			info->args[arg].status = UNSELECTED;
			info->args[arg].delete_group_id = 0;
			if (arg < info->starting_arg)
				info->starting_arg = arg;
			if (arg < info->cursor_arg)
				++info->cursor_coord;
			++info->n_active_args;
		}
		++arg;
	}
	--info->max_delete_group_id;
	if (print_screen(info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
