#include "main.h"

/**
 * handle_str - handler for s
 * @i: pointer to int
 * @list: contains var args
 */
void handle_str(int *i, va_list list)
{
	char *s = va_arg(list, char *);

	while (*s)
	{
		putchar(*s++);
		(*i)++;
	}
}

/**
 * handle_prcnt_and_char - handler for % and c
 * @a: specifier for conversion
 * @i: pointer to int
 * @list: contains var args
 */
void handle_prcnt_and_char(char a, int *i, va_list list)
{
	if (a == '%')
	{
		putchar('%');
		(*i)++;
	}
	else if (a == 'c')
	{
		char c = va_arg(list, int);
		putchar(c);
		(*i)++;
	}
}

/**
 * _printf - produces output according to format
 * @format: char string
 *
 * Return: num of printed chars
 */
int _printf(const char *format, ...)
{
	char a;
	int i = 0;

	va_list list;

	va_start(list, format);

	while ((a = *format++) != '\0')
	{
		if (a != '%')
		{
			putchar(a);
			i++;
		}
		else
		{
			a = *format++;
			if (a == 's')
			{
				handle_str(&i, list);
			}
			else if (a == 'c' || a == '%')
			{
				handle_prcnt_and_char(a, &i, list);
			}
			else
			{
				putchar('%');
				putchar(a);
				i += 2;
			}
		}
	}
	va_end(list);

	return (i);
}
