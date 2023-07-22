#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#define UI_MAX 4725698
/* struct for parametres*/
typedef struct parameters
{
	int plus;
	int minus;
	int zero;
	int hash;
	int space;
	int precision;
	int width;
} parameters;

char* params_modifier(parameters *p, const char *s);
void init_params(parameters *p);

/* struct for functions per specifier*/
typedef struct funct_structs
{
	char *c;
	int (*f)(va_list, parameters*);
}funct_structs;

/* simple print*/
int _putchar(char c);
int _puts(char *s);
/* based of puts and putchar we make the print functions*/
int _print_percent(va_list var, parameters *p);
int _print_string(va_list var, parameters *p);
int _print_char(va_list var, parameters *p);

/* function_getters*/


int (*get_function_with_flags_specs_width_and_precision
(const char *s, parameters *p, funct_structs *specifier))(va_list, parameters *p);






/* the mighty printf*/
int _printf(const char *format, ...);

#endif