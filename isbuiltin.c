#include "simple_shell.h"
int isbuiltin(char *usrcommand)
{
	char *listbi[] = {"cd", NULL};
	int i;

	for (i = 0; listbi[i]; i++)
		if (_strcmp(listbi[i], usrcommand) == 0)
			return (1);
	return (-1);
}
