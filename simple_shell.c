#include "simple_shell.h"
/**
 * signalHandler - Function that catch the signal of crtl c
 * @signum: unused
 * Return: Nothing
 */

void signalHandler(int signum)
{
	(void)signum;
	_putchar('\n');
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	fflush(stdout);
	}

/**
 * main - The main function displays the simple shell
 * @argc: Number of arguments
 * @argv: List of arguments
 * Return: Exit the function on success
 */

int main(int argc, char **argv)
{
	char **toks, *line = NULL, *tmp;
	int int_mode = 1, n, loop_error = 0;
	size_t buf = 0;
	(void)argc;

	signal(SIGINT, signalHandler);
	while (int_mode)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		loop_error++;
		n = getline(&line, &buf, stdin);
		if (parseline(n, line) == -1)
			exit(EXIT_FAILURE);
		toks = create_array(line, " '\n':");
		if (toks[0] == NULL || _strcmp(toks[0], ".") == 0)
		{
			free(toks);
			continue;
		}
		tmp = toks[0];
		if (is_builtin(toks[0]) == -1)
		{
			toks[0] = exist(toks[0]);
			if (toks[0] != NULL)
			{
				execute(toks);
				if (tmp != toks[0])
					free(toks[0]);
			}
			else
				handle_err(tmp, argv, loop_error, line);
		}
		else
			execute_builtin(toks, argv, loop_error, toks[1]);
		tmp = NULL;
		free(toks);
	}
	exit(EXIT_SUCCESS);
}
