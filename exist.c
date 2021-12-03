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
	char *path;
	int i;
	struct stat st;
	char *path, *token, *cppath = NULL, *strtemp;
	char **mainpath;
	int i = 0;

	if (stat(av, &st) == 0)
		return (av);
	path = _getenv("PATH");
	mainpath = malloc(sizeof(char *));
	if (mainpath == NULL)
		return (NULL);
	cppath = malloc(strlen(path) + 1);
	cppath = strcpy(cppath, path);
	token = strtok(cppath, ":");
	printf("token: %s\n", token);
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
	i = 1;
	while (mainpath[i] != NULL)
	{
		mainpath[i] = strcat(mainpath[i], "/");
		  mainpath[i] = strcat(mainpath[i], av);
		printf("%s\n", mainpath[i]);
		if (stat(mainpath[i], &st) == 0)
		{
			strtemp = mainpath[i];
			token = NULL;
			path = NULL;
			free(mainpath);
			return (strtemp);
			}
		i++;
	}
	free(mainpath);
	free(cppath);
	return (NULL);
}
