#ifndef PRINT_F
#define PRINT_F

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
* struct convert - user-defined type for operator and functions
*
* @op: variable for operator
* @f: The function associated
*/
struct convert
{
	char *op;
	int (*f)(va_list);
};
typedef struct convert change;

/* Main functions*/
int _printf(const char *format, ...);
int _vprintf(const char *format, change f_list[], va_list arg_list);
int char_write(char);
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int print_reversed(va_list arg);
int rot13(va_list);
int unsigned_integer(va_list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);


/*Helper functions*/
unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsgined_number(unsigned int);

#endif
