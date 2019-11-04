#include "errors.h"
#include "select.h"
#include "struct_term.h"

int				main(int argc, char **argv)
{
	struct s_term	term;

	if (argc < 2)
		return (print_error(E_USAGE));
	if (setup_terminal(&term) == ERROR)
		return (ERROR);
	if (select(argc, argv, &term))
		return (ERROR);
	if (reset_terminal(&term) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
