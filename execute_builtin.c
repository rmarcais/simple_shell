#include "simple_shell.h"
int execute_builtin(char **av, char **argv, int loop, char *arg)
{
	if (_strcmp(av[0], "cd") == 0)
	{
		if (builtin_cd(av[1]) == -1)
		{
			_printf("%s: %d: can't cd to %s\n", argv[0], loop, arg);
			return (-1);
		}
		return (1);
	}
	if (_strcmp(av[0], "env") == 0 || _strcmp(av[0], "printenv") == 0)
	{
		if (av[1] == NULL)
			builtin_env();
		else
			_printf("%s: '%s': No such file or directory\n",
				av[0], av[1]);
	}
	return (-1);
}
int builtin_cd(char *av)
{
	if (chdir(av) == -1)
		return (-1);
	return (1);
}
int builtin_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		_printf("%s\n", environ[i]);
	return (1);
}
