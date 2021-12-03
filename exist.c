#include "simple_shell.h"
/**
 * exist - checks if a command exist in the path.
 * @av: The array that contains the command of the command
 *
 * Return: On success 0.
 * On error, -1 is returned.
 */
int exist(char *av)
{
	char *path;
	int i;
	struct stat st;

	if (stat(av, &st) == 0)

	path = _getenv("PATH");

	mainpath = malloc(sizeof(char *));
	if (mainpath == 0)
	{
		return (NULL);
	}
	
