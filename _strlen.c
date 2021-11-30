/**
 * _strlen - computes the size of str
 * @str: points to a char
 * Return: count.
 */
int _strlen(char *str)
{
	int count = 0;

	while (str[count])
	{
		count++;
	}
	return (count);
}
