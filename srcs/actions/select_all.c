#include "errors.h"
#include "print.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>

int		action_select_all(struct s_info *info)
{
	uint32_t	arg;
	uint32_t	coord;

	if (info->n_active_args == 0)
		return (SUCCESS);
	arg = info->starting_arg;
	coord = 0;
	while (coord < info->n_active_args)
	{
		if (info->args[arg].status == UNSELECTED)
		{
			info->args[arg].status = SELECTED;
			print_string(&(info->args[arg]), coord, info);
		}
		arg = info->args[arg].active_next;
		++coord;
	}
	return (SUCCESS);
}
