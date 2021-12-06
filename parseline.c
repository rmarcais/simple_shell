#include "simple_shell.h"
int parseline(int n, char *line)
{
	if (n == -1 || _strcmp(line, "exit\n") == 0)
	{
		free(line);
		if (n == -1)
			_putchar('\n');
		return (-1);
	}
	return (1);
}
