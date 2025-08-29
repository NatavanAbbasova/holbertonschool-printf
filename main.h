#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
/**
 * struct spec - typedef
 * @specifier: gjghjh
 * @func: poiiii
 */
typedef struct spec
{
	char *specifier;
	int (*func)(va_list, int);
} spec;

int _printf(const char *format, ...);
int print_char(va_list args, int length);
int print_string(va_list args, int length);
int handle_mod(va_list args, int length);
int print_int(va_list args, int length);
void print_number(int n);

#endif
