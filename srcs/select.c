#include "errors.h"
#include "struct_arg.h"
#include "struct_info.h"
#include "struct_term.h"
#include "ft_printf.h"
#include <ft_mem.h>

int				select(int argc, char **argv, struct s_term *term)
{
	struct s_info	info;
	struct s_arg	*args;
	int				i;

	(void)term;
	setup_info(&info);
	if (setup_args(&args, &info, argc, argv) == ERROR)
		return (ERROR);
	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%s\n", (args[i]).name);
		++i;
	}
	ft_memdel((void **)&args);
	return (SUCCESS);
}
