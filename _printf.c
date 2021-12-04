#include "simple_shell.h"
/**
 * _printf - formats and prints data
 * @format: data to print
 * Return: the length of fotmat
 */
int _printf(const char *format, ...)
{
	va_list ap;
	spe spe[] = {{"s", print_s}, {"c", print_c}, {"d", print_int},
		      {"i", print_int}, {"%", print_percent},
		      {"b", convert_binary}, {NULL, NULL}};
	int i, j, len = 0;

	if (format == 0 || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			len += _putchar(format[i]);
		else if (format[i + 1] != 's' && format[i + 1] != 'c' &&
			 format[i + 1] != 'd' && format[i + 1] != 'i' &&
			format[i + 1] != '%' && format[i + 1] != 'b')
		{
			len += _putchar(format[i]);
			len += _putchar(format[i + 1]);
			i++;
		}
		else
		{
			for (j = 0; spe[j].specifier != NULL; j++)
				if (format[i + 1] == *spe[j].specifier)
					len += spe[j].f(ap);
			i++;
		}
	}
	va_end(ap);
	return (len);
}
