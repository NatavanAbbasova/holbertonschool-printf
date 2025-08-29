#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
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
 * print_number - ozuduuuuu
 * @n: number
 * Return: RRRRRRRRRRRR
 */
void print_number(int n)
{
	if (n / 10)
		print_number(n / 10);
	putchar((n % 10 + '0');
}

/**
 * print_int - vaaaaaaa
 * @args: argument
 * @length: length
 * Return: returnnnnnnnnnnn
 */
int print_int(va_list args, int length)
{
	int n = va_arg(args, int);
	int printed = print_number(n);
	return (length + printed);
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

	if (!format)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}
			for (j = 0; format_spec[j].specifier != NULL; j++)
			{
				if (format[i + 1] == format_spec[j].specifier[0])
				{
					length = format_spec[j].func(args, length);
					i++;
					break;
				}
			}
		}
		else
		{
			putchar(format[i]);
			length++;
		}
	}

	va_end(args);
	return (length);
}
