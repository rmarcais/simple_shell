#include "simple_shell.h"
int exebi(char *av0, char *av1)
{
	if (_strcmp(av0, "cd") == 0)
	{
		bi_cd(av1);
		return (1);
	}
	return (-1);
}
