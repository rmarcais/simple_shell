#include "simple_shell.h"
/**
 * parseline - parses the line
 * @n: return value of the getline function
 * @line: line to parse
 * Return: 1 or -1
 */
int parseline(int n, char *line)
{
	char *token;

	if (n == -1 || _strcmp(line, "exit\n") == 0)
	{
		free(line);
		if (n == -1)
			_putchar('\n');
		return (-1);
	}
	else
	{
		token = strtok(line, " '\n'");
		if (_strcmp(token, "exit") == 0)
		{
			free(line);
			return (-1);
		}
	}
	return (1);
}
