#ifndef PRINT_F
#define PRINT_F

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;

/* Main functions*/
int _printf(const char *format, ...);

#endif
