#include "simple_shell.h"

/**
 * _strcmp - function that compares two strings
 *
 * @s1: string compare to string s2
 * @s2: string compare to string s1
 *
 * Return: The difference between the two strings
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
