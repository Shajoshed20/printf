#include "main.h"

/**
 * _printf - Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired characters
 * Return: A total count of the characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	change f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	/*Calling _vprintf function*/
	printed_chars = _vprintf(format, f_list, arg_list);
	va_end(args);
	return (printed_chars);
}
