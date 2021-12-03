#include "simple_shell.h"
/**
 * split_path - split the path of the given command
 * @av: The array that contains the path of the command
 * @delimiter: the character given to delimit the tokens
 * Return: 0 On success or -1 on Error.
 */
char **split_path(char *av, char *delimiter)
{
	char **mainpath;
	char *token;
	int i = 0;

	av = _strdup(getenv("PATH"));
	mainpath = malloc(sizeof(char *));
	if (mainpath == NULL)
		return (NULL);
	token = strtok(av, delimiter);
	while (token != NULL)
	{
		mainpath[i] = token;
		mainpath = _realloc(mainpath, sizeof(mainpath) * (i + 1),
			      (sizeof(mainpath) * (i + 1) + sizeof(char *)));
		if (mainpath == NULL)
			return (NULL);
		token = strtok(NULL, delimiter);
		i++;
	}
	mainpath[i] = token;
	return (mainpath);
}
