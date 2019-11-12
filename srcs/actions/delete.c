#include "errors.h"
#include "screen.h"
#include "print.h"
#include "actions.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>

int		action_delete(struct s_info *info)
{
	if (info->n_active_args == 0)
		return (SUCCESS);
	if (clear_screen(info) == ERROR)
		return (ERROR);
	info->args[info->args[info->cursor_arg].active_next].active_prev =
		info->args[info->cursor_arg].active_prev;
	info->args[info->args[info->cursor_arg].active_prev].active_next =
		info->args[info->cursor_arg].active_next;
	--(info->n_active_args);
	++(info->max_delete_group_id);
	info->args[info->cursor_arg].status = DELETED;
	info->args[info->cursor_arg].delete_group_id = info->max_delete_group_id;
	if (info->cursor_arg == info->starting_arg)
		info->starting_arg = info->args[info->cursor_arg].active_next;
	info->cursor_arg = info->args[info->cursor_arg].active_next;
	if (print_screen(info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
