#include "simple_shell.h"
#include "stdlib.h"

/**
 * _strdup - duplicate an array of chars
 * @str: pointer to an array
 * Return: the array duplicated
 */

char *_strdup(char *str)
{
	int n;
	int i;
	char *dest;

	if (str == 0)
	{
		return (0);
	}
	for (n = 0; str[n] != '\0'; n++)
	{
		;
	}
	dest = malloc(n * sizeof(char) + 1);
	if (dest == 0)
	{
		return (0);
	}
	for (i = 0; i < n; i++)
	{
		dest[i] = str[i];
	}
	return (dest);
}
