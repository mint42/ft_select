



#include "print.h"
#include "struct_info.h"
#include "struct_arg.h"
#include <stdint.h>

void	l_key(struct s_info *info)
{
	uint32_t	prev_cursor_arg;
	uint32_t	prev_cursor_coord;

	prev_cursor_arg = info->cursor_arg;
	prev_cursor_coord = info->cursor_coord;
	info->cursor_arg = info->args[info->cursor_arg].active_next;
	if (prev_cursor_arg >= info->cursor_arg)
		info->cursor_coord = 0;
	else
		++(info->cursor_coord);
	print_string(&(info->args[prev_cursor_arg]), prev_cursor_coord, info);
	print_string(&(info->args[info->cursor_arg]), info->cursor_coord, info);
}

void	h_key(struct s_info *info)
{
	uint32_t	prev_cursor_arg;
	uint32_t	prev_cursor_coord;

	prev_cursor_arg = info->cursor_arg;
	prev_cursor_coord = info->cursor_coord;
	info->cursor_arg = info->args[info->cursor_arg].active_prev;
	if (prev_cursor_arg <= info->cursor_arg)
		info->cursor_coord = info->n_active_args - 1;
	else
		--(info->cursor_coord);
	print_string(&(info->args[prev_cursor_arg]), prev_cursor_coord, info);
	print_string(&(info->args[info->cursor_arg]), info->cursor_coord, info);
}

void	j_key(struct s_info *info)
{
	(void)info;
	return ;
}

void	k_key(struct s_info *info)
{
	(void)info;
	return ;
}

void	a_key(struct s_info *info)
{
	uint32_t	arg;
	uint32_t	coord;

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
}

void	d_key(struct s_info *info)
{
	--(info->n_active_args);
	(void)info;
	return ;
}

void	r_key(struct s_info *info)
{
	(void)info;
	return ;
}

void	q_key(struct s_info *info)
{
	(void)info;
	return ;
}

void	u_key(struct s_info *info)
{
	(void)info;
	return ;
}

void	questn_key(struct s_info *info)
{
	(void)info;
	return ;
}

void	fslash_key(struct s_info *info)
{
	(void)info;
	return ;
}

void	space_key(struct s_info *info)
{
	uint32_t	prev_cursor_arg;
	uint32_t	prev_cursor_coord;

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
}
