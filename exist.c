#include "simple_shell.h"
/**
 * exist - checks if a command exist in the path.
 * @av: The array that contains the command of the command
 *
 * Return: On success 0.
 * On error, -1 is returned.
 */
int exist(char **av)
{
	struct stat st;
	char *value, *token;
	int i = 0;
	char **path;
	char *tmp;

	value = _getenv("PATH");
	path = malloc(sizeof(char *));
	if (path == NULL)
		exit(EXIT_FAILURE);
	token = strtok(value, ":");
	while(token != NULL)
	{
		path[i] = token;
		token = strtok(NULL, ":");
		path = _realloc(path, sizeof(char *) * (i + 1),
				(sizeof(av) * (i + 1) + sizeof(char *)));
		if (path == NULL)
			exit(EXIT_FAILURE);
		i++;
	}
	path[i] = token;
	i = 0;
	tmp = av[0];
	while (path[i] != NULL)
	{
		chdir(path[i]);
		if (stat(av[0], &st) == 0)
		{
			av[0] = strcat(path[i], "/");
			av[0] = strcat(av[0], tmp);
			return (0);
		}
	}
	return (-1);
	/*if (stat(av[0], &st) == 0)
		return (0);
	else
	return(-1);*/
}
