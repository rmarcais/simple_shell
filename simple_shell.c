#include "simple_shell.h"
int main(void)
{
	char **toks;
	char *line = NULL;
	int int_mode = 1, n;
	size_t buf = 0;

	while (int_mode)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		}
		n = getline(&line, &buf, stdin);
		if (n == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		if (line[0] == '\n')
		{
			continue;
		}
		toks = create_array(line, " :'\n''\t'");
		if (execute(toks) == -1)
		{
			free(line);
			free(toks);
			break;
		}
		free(toks);
	}
	exit (EXIT_SUCCESS);
}
