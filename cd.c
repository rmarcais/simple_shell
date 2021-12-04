#include "simple_shell.c"
void bi_cd(char *directory)
{
	if (chdir(directory) == -1)
		return;
}
