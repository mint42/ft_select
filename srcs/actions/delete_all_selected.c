#include "errors.h"
#include "screen.h"
#include "actions.h"
#include "print.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>

static void		delete_selected(struct s_info *info, uint32_t arg, uint32_t coord)
{
	static uint8_t	first;

	if (first == 0)
		++(info->max_delete_group_id);
	first = 1;
	info->args[info->args[arg].active_next].active_prev =
		info->args[arg].active_prev;
	info->args[info->args[arg].active_prev].active_next =
		info->args[arg].active_next;
	info->args[arg].delete_group_id = info->max_delete_group_id;
	info->args[arg].status = DELETED;
	if (arg == info->starting_arg)
		info->starting_arg = info->args[info->starting_arg].active_next;
	if (arg == info->cursor_arg)
	{
		if (coord == info->n_active_args - 1)
		{
			--info->cursor_coord;
			info->cursor_arg = info->args[arg].active_prev;
		}
		else
			info->cursor_arg = info->args[arg].active_next;
	}
	else if (arg < info->cursor_arg)
		info->cursor_arg = info->args[info->cursor_arg].active_next;
	--info->n_active_args;
}

int				action_delete_all_selected(struct s_info *info)
{
	uint32_t	prev_active_args;
	uint32_t	arg;
	uint32_t	coord;

	if ((info->n_active_args - info->n_selected_args) == 0)
		return (BREAK);
	if (clear_screen(info) == ERROR)
		return (ERROR);
	prev_active_args = info->n_active_args;
	arg = info->starting_arg;
	coord = 0;
	while (coord < prev_active_args)
	{
		if (info->args[arg].status == SELECTED)
			delete_selected(info, arg, coord);
		arg = info->args[arg].active_next;
		++coord;
	}
	info->n_selected_args = 0;
	info->s_len = 0;
	if (print_screen(info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
