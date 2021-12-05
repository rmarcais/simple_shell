#include "simple_shell.h"
int is_builtin(char *command)
{
	char *built_in[] = {"cd", "env", "printenv",  NULL};
	int i;

	for (i = 0; built_in[i]; i++)
		if (_strcmp(built_in[i], command) == 0)
			return (1);
	return (-1);
}
