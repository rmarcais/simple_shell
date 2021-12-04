#include "simple_shell.h"
/**
 * print_s - prints a string
 * @ap: name of the va_list
 * Return: the number of characters
 */
int print_s(va_list ap)
{
	char *str;
	char *str_null = "(null)";
	int i = 0;

	str = va_arg(ap, char *);

	if (str == 0)
	{
		while (str_null[i])
			_putchar(str_null[i++]);
		return (6);
	}
	while (str[i])
	{
		_putchar(str[i++]);
	}
	return (i);
}
/**
 * print_c - prints a character
 * @ap: name of the va_list
 * Return: 1
 */
int print_c(va_list ap)
{
	_putchar(va_arg(ap, int));
	return (1);
}
/**
 * print_int - prints an integer
 * @ap: name of the va_list
 * Return: the number of characters
 */
int print_int(va_list ap)
{
	long int n = va_arg(ap, int), count = 0, div = 1;
	unsigned int num;

	if (n < 0)
	{
		count += _putchar('-');
		n *= -1;
	}
	num = n;
	while (num / (div * 10) >= 1)
		div *= 10;
	while (div >= 1)
	{
		count += _putchar(num / div + '0');
		num = num % div;
		div /= 10;
	}
	return (count);
}
/**
 * print_percent - prints the percent sign
 * @ap: name of the va_list
 * Return: 1
 */
int print_percent(va_list ap)
{
	(void)ap;
	_putchar('%');
	return (1);
}
/**
 * convert_binary - converts an unsigned integer in to binary
 * @ap: name of the va_list
 * Return: the number of characters
 */
int convert_binary(va_list ap)
{
	unsigned long int n = va_arg(ap, int), bin = 0;
	int count = 0;
	unsigned int i = 1, rem = 1, div = 1;

	while (n != 0)
	{
		rem = n % 2;
		n /= 2;
		bin += rem * i;
		i *= 10;
	}
	while (bin / (div * 10) >= 1)
		div *= 10;
	while (div >= 1)
	{
		count += _putchar(bin / div + '0');
		bin %= div;
		div /= 10;
		}
	return (count);
}
