#include "errors.h"
#include "screen.h"
#include "print.h"
#include "actions.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>

int		action_delete(struct s_info *info)
{
	--(info->n_active_args);
	if (info->n_active_args == 0)
		return (BREAK);
	if (clear_screen(info) == ERROR)
		return (ERROR);
	if (info->args[info->cursor_arg].status == SELECTED)
	{
		info->s_len = info->s_len - info->args[info->cursor_arg].len;
		--info->n_selected_args;
	}
	info->args[info->args[info->cursor_arg].active_next].active_prev =
		info->args[info->cursor_arg].active_prev;
	info->args[info->args[info->cursor_arg].active_prev].active_next =
		info->args[info->cursor_arg].active_next;
	++(info->max_delete_group_id);
	info->args[info->cursor_arg].status = DELETED;
	info->args[info->cursor_arg].delete_group_id = info->max_delete_group_id;
	if (info->cursor_arg == info->starting_arg)
		info->starting_arg = info->args[info->cursor_arg].active_next;
	if (info->cursor_coord == info->n_active_args)
	{
		--info->cursor_coord;
		info->cursor_arg = info->args[info->cursor_arg].active_prev;
	}
	else
		info->cursor_arg = info->args[info->cursor_arg].active_next;
	if (print_screen(info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
