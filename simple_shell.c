#include "simple_shell.h"
int main(void)
{
	char **toks;
	char *line = NULL, *token;
	int int_mode = 1, i = 0, pid;
	size_t buf = 0;

	while (int_mode)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		}
		getline(&line, &buf, stdin);
		toks = malloc(sizeof(char *) * 1);
		token = strtok(line, "' ':'\n''\t'");
		while (token != NULL)
		{
			toks[i] = strdup(token);
			token = strtok(NULL, " :'\n''\t'");
			toks = realloc(toks, sizeof(char *));
			i++;
		}
		toks[i] = token;
		free(token);
		pid = fork();
		if(!pid)
		{
			if (execve(toks[0], toks, NULL) == -1)
			{
				free(toks);
				printf("Error\n");
			}
		}
		i = 0;
		wait(NULL);
	}
	return (0);
}
