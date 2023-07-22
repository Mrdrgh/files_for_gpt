#include "main.h"
/**
 * _putchar - puts a char
 * @c: the char
 * Return: 1 if true 0 if false
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - using puchar , output
 * @s: the string
 * Return: the number of chars to print
*/
int _puts(char *s)
{
	char *p = s;
	int i = 0;

	while (*p)
	{
		_putchar(*p);
		p++;
		i++;
	}
	return (i);
}