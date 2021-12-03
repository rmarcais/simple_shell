#include "simple_shell.h"
/**
 * exist - checks if a command exist in the path.
 * @av: The array that contains the command of the command
 *
 * Return: On success 0.
 * On error, -1 is returned.
 */
char *exist(char *av)
{
	struct stat st;
	char *path, *bin = NULL, *token;
	char **mainpath;
	int i = 0;

	if (stat(av, &st) == 0)
		return (av);
	path = strdup(getenv("PATH"));
	mainpath = malloc(sizeof(char *));
	if (mainpath == NULL)
		return (NULL);
	token = strtok(path, ":");
	while (token != NULL)
	{
		mainpath[i] = token;
		mainpath = _realloc(mainpath, sizeof(mainpath) * (i + 1),
			      (sizeof(mainpath) * (i + 1) + sizeof(char *)));
		if (mainpath == NULL)
			return (NULL);
		token = strtok(NULL, ":");
		i++;
	}
	mainpath[i] = token;
	free(path);
	path = NULL;
	for (i = 0; mainpath[i]; i++)
	{
		bin = calloc(sizeof(char), (strlen(mainpath[i])
					    + 1 + strlen(av) + 1));
		if (bin == NULL)
			return (NULL);
		_strcat(bin, mainpath[i]);
		_strcat(bin, "/");
		strcat(bin, av);
		if (stat(bin, &st) == 0)
		{
			free(mainpath);
			return (bin);
		}
		free(bin);
		bin = NULL;
	}
	free(mainpath);
	return (NULL);
}
