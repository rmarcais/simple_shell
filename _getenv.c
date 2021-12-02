#include "simple_shell.h"
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
			return(token);
		}
	}
	return (0);
}
