#include "main.h"
#include <stdlib.h>


char *_memcpy(char *dest, char *src, unsigned int n);


/**
 * _realloc - reallocation of memory in new size
 * @ptr: pointeur
 * @old_size: first size
 * @new_size: last size
 * Return: nptr
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{

	void *nptr;

	if (new_size == old_size)
		return (ptr);
	if (ptr == 0)
	{
		free(ptr);
		ptr = malloc(new_size);
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL); /* is equivalent to free(ptr)*/
	}
	nptr = malloc(new_size);
	if (nptr == 0)
		return (0);
	_memcpy(nptr, ptr, old_size);
	free(ptr);
	return (nptr);
}

/**
 * _memcpy - this function copy a string of bite in the memory
 * @dest: char
 * @src: char
 * @n: unsigned int
 * Return: 0
 */

char *_memcpy(char *dest, char *src, unsigned int n)

{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = *src++;
	}
	return (dest);
}
