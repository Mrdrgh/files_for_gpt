#include "main.h"
/**
 * _printf - printf
 * @format: the format to print
 * Return: the number of chars printed
*/
int _printf(const char *format, ...)
{
	va_list var;
	int j = 0;
	const char *p;
	int (*function_pointer)(va_list, parameters*);
	/* initialize the specifiers and thier respective functs*/
	funct_structs spec_struct[] = {
		{"c", _print_string},
		{"s", _print_string},
		{"%", _print_string},
		{NULL, NULL}
	};
	/* initialize the parameters*/
	parameters params;
	init_params(&params);

	va_start(var, format);	
	if (!format)
		return (-1);
	p = format;
	while (*p)
	{
		if (*p != '%')
		{
			j += _putchar(*p);
			p++;
		}
		else
		{
			function_pointer = get_function_with_flags_specs_width_and_precision(p, &params, spec_struct);
			if (!function_pointer)
			{
				j += _putchar(*p);
				p++;
			}
			else
			{
				j += function_pointer(var, &params);
			}
		}
		p++;
	}
	return (j);
}