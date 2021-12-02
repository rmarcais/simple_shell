#include "simple_shell.h"

/**
 * _getenv - the function take the value of the variable
 * @name: this variable is the name of the variable
 * Return: the value of the variable
 */

char *_getenv(const char *name)
{
	char *token;
	int i;

	extern char **environ;

	for (i = 0; environ[i]; i++)
	{
		token = strtok(environ[i], "=");
		if (strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=");
			return (token);
		}
	}
	return (0);
}
