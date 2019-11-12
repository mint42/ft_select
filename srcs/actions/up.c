#include "errors.h"
#include "print.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>

static void		move_cursor_up(struct s_info *info)
{
	uint32_t	i;

	i = 0;
	while (i < info->n_columns)
	{
		info->cursor_arg = info->args[info->cursor_arg].active_prev;
		if (info->cursor_coord == 0)
			info->cursor_coord = info->n_active_args - 1;
		else
			--info->cursor_coord;
		++i;
	}
}

static void		move_cursor_down_and_left(struct s_info *info)
{
	uint32_t	column_to_stop_on;

	if (info->cursor_coord % info->n_columns == 0)
		column_to_stop_on = info->n_columns - 1;
	else
		column_to_stop_on = (info->cursor_coord % info->n_columns) - 1;
	info->cursor_arg = info->args[info->starting_arg].active_prev;
	info->cursor_coord = info->n_active_args - 1;
	while (column_to_stop_on != (info->cursor_coord % info->n_columns))
	{
		info->cursor_arg = info->args[info->cursor_arg].active_prev;
		if (info->cursor_coord == 0)
			info->cursor_coord = info->n_active_args - 1;
		else
			--info->cursor_coord;
	}
}

int				action_up(struct s_info *info)
{
	uint32_t	prev_cursor_arg;
	uint32_t	prev_cursor_coord;

	if (info->n_active_args == 1)
		return (SUCCESS);
	prev_cursor_arg = info->cursor_arg;
	prev_cursor_coord = info->cursor_coord;
	if (info->cursor_coord >= info->n_columns)
		move_cursor_up(info);
	else
		move_cursor_down_and_left(info);
	print_string(&(info->args[prev_cursor_arg]), prev_cursor_coord, info);
	print_string(&(info->args[info->cursor_arg]), info->cursor_coord, info);
	return (SUCCESS);
}
