#include "simple_shell.h"

/**
 * is_builtin - function that compare the output with an array
 * @command: takes the name of the command
 * Return: Return -1 on error and 1 on succeed
 */



int is_builtin(char *command)
{
	char *built_in[] = {"cd", "env", "printenv",  NULL};
	int i;

	for (i = 0; built_in[i]; i++)
		if (_strcmp(built_in[i], command) == 0)
			return (1);
	return (-1);
}
