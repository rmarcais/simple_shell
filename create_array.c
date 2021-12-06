#include "simple_shell.h"

/**
 * create_array - This function create an array of input given by the user
 * @line: input of the user
 * @delimiter: a pointer to the character given by the user
 * to split the input
 * Return: return the entire array
 */

char **create_array(char *line, char *delimiter)
{
	char **av, *token;
	int i = 0;

	av = malloc(sizeof(char *) * 1);
	if (av == NULL)
		exit(-1);
	token = strtok(line, delimiter);
	while (token != NULL)
	{
		av[i] = token;
		token = strtok(NULL, delimiter);
		av = _realloc(av, sizeof(av) * (i + 1),
			      (sizeof(av) * (i + 1) + sizeof(char *)));
		if (av == NULL)
			exit(-1);
		i++;
	}
	av[i] = token;
	return (av);
}
