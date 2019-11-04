#include "errors.h"
#include "struct_arg.h"
#include "struct_info.h"
#include "ft_mem.h"
#include "ft_str.h"

int	setup_args(struct s_arg **args, struct s_info *info, int argc, char **argv)
{
	int		i;

	*args = (struct s_arg *)ft_memalloc(sizeof(struct s_arg) * argc - 1);
	if (!*args)
		return (print_error(E_MALLOC));
	i = 0;
	while (i < argc)
	{
		((*args)[i]).name = argv[i + 1];
		((*args)[i]).len = ft_strlen(((*args)[i]).name);
		((*args)[i]).status = ACTIVE;
		if (i == 0)
			((*args)[i]).active_prev = argc - 1;
		else
			((*args)[i]).active_prev = i - 1;
		if (i == argc - 1)
			((*args)[i]).active_next = 0;
		else
			((*args)[i]).active_next = i + 1;
		((*args)[i]).finder_prev = 0;
		((*args)[i]).finder_next = 0;
		if (((*args)[i]).len > info->max_name_len)
			info->max_name_len = ((*args)[i]).len;
		++i;
	}
	return (SUCCESS);
}
