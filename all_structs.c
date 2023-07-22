#include "main.h"
#define FALSE 0
#define TRUE 1
/**
 * init_struct_paramaters - initializes the struct of parameters
 * @p: the struct
*/
void init_params(parameters *p)
{
	p->hash = 0;
	p->minus = 0;
	p->plus = 0;
	p->precision = UI_MAX;
	p->space = 0;
	p->width = 0;
	p->zero = 0;
}
/**
 * params_modifier - modifies the params of the params struct based on what
 * he finds after the percent char
 * @p: the struct of params
 * @s: the pointer to the stack where -what-after-percent locates
*/
char* params_modifier(parameters *p, const char *s)
{
	unsigned int isPrecision = FALSE;
	unsigned int isWidth = FALSE;

	if (!s)
		return (NULL);
	while (*s)
	{
		switch(*s)
		{
			case '.':
				isPrecision = TRUE;
				isWidth = FALSE;
				s++;
				break;
			case 'c':
				s++;
				return ("c");
			case 's':
				s++;
				return ("s");
			default:
				if (*s >= 0 && *s <= 9)
				{
					if (isPrecision)
					{
						p->precision = p->precision * 10 + *(s) - '0';
					}
					else if (isWidth)
					{
						p->width = p->width * 10 + *(s) - '0';
					}
					else 
					{
						isWidth = TRUE;
						p->width = *s - '0';
					}
				}
				s++;
				break;
		}
		
	}
	return (NULL); /* it found nothing , returns NULL*/	
}
/**
 * get_function_with_flags_specs_width_and_precision - based on the return 
 * of params_modifierfunction ,this function will return the right function
 * for the char returned if NULL, we return to start ,
 * start is defined where we first met the percentage
 * @s: the start pointer , it points to the start of chars right after the %
 * Return: the number of chars printed
*/
int (*get_function_with_flags_specs_width_and_precision 
(const char *s,parameters *p, funct_structs *specifier))(va_list var, parameters *p)
{
	const char *start = s;
	const char *specifier_char;
	int i = 0;
	
	s++;
	specifier_char = params_modifier(p, s);
	if (!specifier_char)
	{
		s = start; /* start is %*/
		return (NULL);
	}
	while ((specifier[i].c) != NULL)
	{
		if (*(params_modifier(p, s)) == specifier[i].c[0])
		{
			return (specifier[i].f);
		}
		i++;
	}
	s = start;
	return (NULL);	
}












































/**
 * #include <stdbool.h>

void params_modifier(parameters *p, char *s) {
    bool isPrecision = false;
    bool isWidth = false;

    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case '+':
                p->plus = 1;
                break;
            case '-':
                p->minus = 1;
                break;
            case '0':
                p->zero = 1;
                break;
            case '#':
                p->hash = 1;
                break;
            case ' ':
                p->space = 1;
                break;
            case '.':
                isPrecision = true;
                isWidth = false;
                break;
            default:
                if (s[i] >= '1' && s[i] <= '9') {
                    if (isPrecision) {
                        p->precision = p->precision * 10 + (s[i] - '0');
                    } else if (isWidth) {
                        p->width = p->width * 10 + (s[i] - '0');
                    } else {
                        isWidth = true;
                        p->width = s[i] - '0';
                    }
                }
                break;
        }
    }
}

*/