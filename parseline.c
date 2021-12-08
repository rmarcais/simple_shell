#include "simple_shell.h"
/**
 * parseline - parses the line
 * @n: return value of the getline function
 * @line: line to parse
 * Return: 1 or -1
 */
int parseline(int n, char *line)
{
	char *token, *line2;

	if (n == -1 || _strcmp(line, "exit\n") == 0)
	{
		free(line);
		if (n == -1)
			/*_putchar('\n');*/
		return (-1);
	}
	else
	{
		line2 = _strdup(line);
		token = strtok(line2, " '\n'");
		if (token == NULL)
		{
			free(line2);
			return (1);
		}
		if (_strcmp(token, "exit") == 0)
		{
			free(line);
			free(line2);
			return (-1);
		}
	}
	free(line2);
	return (1);
}
