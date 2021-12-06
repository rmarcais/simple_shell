#include "simple_shell.h"

/**
 * handle_err - manage errors
 * @av: the command of the user
 * @argv: number of arguments
 * @loop: counter for the number of loops
 * @line: takes the string of line
 */



void handle_err(char *av, char **argv, int loop, char *line)
{
	if (_strlen(line) >= 256)
		_printf("%s: %d: %s: File name too long\n", argv[0], loop, av);
	else
	_printf("%s: %d: %s: not found\n", argv[0], loop, av);
}
