#ifndef main_h
#define main_h
#include <stdarg.h>

void handle_str(int *i, va_list list);
void handle_prcnt_and_char(char a, int *i, va_list list);
int _printf(const char *format, ...);

#endif
