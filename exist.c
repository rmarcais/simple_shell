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
	char *path, *token, *strtemp;
	char **mainpath;
	int i = 0;

	if (stat(av, &st) == 0)
		return (av);
	
