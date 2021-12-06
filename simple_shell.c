#include "simple_shell.h"
/**
 * main - The main function displays the simple shell
 * @argc: Number of arguments
 * @argv: List of arguments
 * Return: Exit the function on success
 */
void signalHandler(int signum)
{
	(void)signum;
	_putchar('\n');
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	fflush(stdout);
	}
int main(int argc, char **argv)
{
	char **toks, *line = NULL, *tmp;
	int int_mode = 1, n, loop_error = 1;
	size_t buf = 0;
	(void)argc;

	signal(SIGINT, signalHandler);
	while (int_mode)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		n = getline(&line, &buf, stdin);
		if (parseline(n, line) == -1)
			exit(EXIT_FAILURE);
		if (line[0] == '\n')
			continue;
		toks = create_array(line, " :'\n''\t'");
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
				handle_err(tmp, argv, loop_error);
		}
		else
			execute_builtin(toks, argv, loop_error, toks[1]);
		tmp = NULL;
		free(toks);
		loop_error++;
	}
	exit(EXIT_SUCCESS);
}
