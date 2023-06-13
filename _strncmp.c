#include "simple_shell.h"
/**
 * *_strncmp - function that compare the n first characters of two strings
 * @s1: string that receives a copy of variable src string
 * @s2: string copy in the variable dest string
 * @n: n
 *
 * Return: a pointer to the resulting string dest
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

	return (0);
}
