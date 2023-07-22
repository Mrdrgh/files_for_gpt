#include "main.h"
/**
 * _print_string - prints a string based on the precision
 * @var: the list of vars
 * @p: the parametres already modified with the function pars_modifier
 * Return: the number of chars printed
*/
int _print_string(va_list var, parameters *p)
{
	char *s = va_arg(var, char*);
	int j = _puts(s);
	init_params(p);
	return (j);
}
