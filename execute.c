#include "simple_shell.h"

/**
 * execute - This function execute the function given by the user
 * @av: take the array that contain the command of the user
 * Return: Return 0 on succes or -1 on error
 */

int execute(char **av)
{
	int pid = fork();

	if(!pid)
	{
		if (execve(av[0], av, NULL) == -1)
		{
			perror(av[0]);
		}
	}
	else
		wait(NULL);
	return (1);
}
