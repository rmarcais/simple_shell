#include "simple_shell.h"
void handle_err(char *av, int loop)
{
	printf("./hsh: %d: %s: not found\n", loop, av);
}
