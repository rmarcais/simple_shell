#include "simple_shell.h"
/**
 * _calloc - allocates memory for an array
 * @nmemb: takes an unsigned value
 *@size: takes an ansigned value
 * Return: a pointer to the allocate memory or NULL.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (NULL);
	_memset(ptr, 0, nmemb * size);
	return (ptr);
}
/**
 * _memset - prints buffer in hexa
 * @s: points to a character
 * @b: character
 *@n: take an unsigned integer value
 * Return: Nothing.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
