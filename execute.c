#include "simple_shell.h"
int execute(char **av)
{
	int pid = fork();

	if(!pid)
	{
		if (execve(av[0], av, NULL) == -1)
		{
			printf("Error\n");
			return (-1);
		}
	}
	else
		wait(NULL);
	return (0);
}
