#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * print_char - ozududeeee
 * @args: jfdoifopfiopf
 * @length: lennn
 * Return: RRR
 */
int print_char(va_list args, int length)
{
	putchar(va_arg(args, int));
	return (length + 1);
}

/**
 * print_string - ele ozuduuuu
 * @args: fklgkghk
 * @length: len
 * Return: RRRRRRRR
 */
int print_string(va_list args, int length)
{
	int i;
	char *str = va_arg(args, char *);
	char *nil = "(null)";

	if (str)
	{
		for (i = 0; str[i]; i++)
			putchar(str[i]);
		length += i;
	}
	else
	{
		for (i = 0; nil[i]; i++)
			putchar(nil[i]);
		length += i;
	}
	return (length);
}

/**
 * handle_mod - men demisdim %i menimsetek beyinnnnn
 * @args: hkfjdlfjljfl
 * @length: len
 * Return: R himmmmmmmmmm
 */
int handle_mod(va_list args, int length)
{
	(void) args;
	putchar('%');
	return (length + 1);
}

/**
 * print_int - vaaaaaaa
 * @args: argument
 * @length: length
 * Return: returnnnnnnnnnnn
 */
int print_int(va_list args, int length)
{
	int i;
	char number[100];

	sprintf(number, "%d", va_arg(args, int));
	for (i = 0; number[i]; i++)
		putchar(number[i]);
	length += i;
	return (length);
}

/**
 * _printf - arqumenti print edecek
 * @format: format
 * Return: returnnm
 */
int _printf(const char *format, ...)
{
	int i, j, length = 0;
	va_list args;
	spec format_spec[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", handle_mod},
		{"i", print_int},
		{"d", print_int},
		{NULL, NULL}
	};
	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (strlen(format) < 2 && format[i] == '%')
				return (-1);
			for (j = 0; format_spec[j].specifier != NULL; j++)
			{
				if (format[i + 1] == format_spec[j].specifier[0])
				{
					length = format_spec[j].func(args, length);
					i++;
					break;
				}
			}
		} else
		{
			if (i == 1 && strlen(format) <= 3)
				return (write(1, format, strlen(format)));
			putchar(format[i]);
			length++;
		}
	}
	return (length);
}
