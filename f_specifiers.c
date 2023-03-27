#include "main.h"

/**
 * print_char - Function to print character
 * @arg_list: variable for list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_char(va_list arg_list)
{
	char_write(va_arg(arg_list, int));
	return (1);
}
