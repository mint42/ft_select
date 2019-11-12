#include "errors.h"
#include "print.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>

int		action_select(struct s_info *info)
{
	uint32_t	prev_cursor_arg;
	uint32_t	prev_cursor_coord;

	if (info->n_active_args == 0)
		return (SUCCESS);
	prev_cursor_arg = info->cursor_arg;
	prev_cursor_coord = info->cursor_coord;
	info->cursor_arg = info->args[info->cursor_arg].active_next;
	if (prev_cursor_arg >= info->cursor_arg)
		info->cursor_coord = 0;
	else
		++(info->cursor_coord);
	if (info->args[prev_cursor_arg].status == UNSELECTED)
		info->args[prev_cursor_arg].status = SELECTED;
	else
		info->args[prev_cursor_arg].status = UNSELECTED;
	print_string(&(info->args[prev_cursor_arg]), prev_cursor_coord, info);
	print_string(&(info->args[info->cursor_arg]), info->cursor_coord, info);
	return (SUCCESS);
}
