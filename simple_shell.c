#include "simple_shell.h"
/**
 * main - The main function displays the simple shell
 * Return: Exit the function on success
 */

int main(void)
{
	char **toks;
	char *line = NULL, *tmp;
	int int_mode = 1, n, loop_error = 1;
	size_t buf = 0;

	while (int_mode)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		}
		n = getline(&line, &buf, stdin);
		if (n == -1 || _strcmp(line, "exit\n") == 0)
		{
			free(line);
			if (n == -1)
				_putchar('\n');
			exit(EXIT_FAILURE);
		}
		if (line[0] == '\n')
			continue;
		toks = create_array(line, " :'\n''\t'");
		tmp = toks[0];
		toks[0] = exist(toks[0]);
		if (toks[0] != NULL)
		{
			execute(toks);
			if (tmp != toks[0])
				free(toks[0]);
		}
		else
			handle_err(tmp, loop_error);
		tmp = NULL;
		free(toks);
		loop_error++;
	}
	exit(EXIT_SUCCESS);
}
