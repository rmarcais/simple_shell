#include "simple_shell.h"
void handle_err(char *av, char **argv, int loop)
{
	_printf("%s: %d: %s: not found\n", argv[0], loop, av);
}
