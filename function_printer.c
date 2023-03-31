#include "main.h"
/**
 * funct_print - Function for typr argument
 * @format: Variable for format for string
 * @list: Variable for argument list
 * @ind: variable for ..
 * @buffer: varibale for buffer
 * @flags: Variable for flags calculated
 * @width: variable to obtaine width
 * @precision: variable for precision spec
 * @size: variable for size
 * Return: integer type
 */
int funct_print(const char *format, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	format_t format_types[] = {
		{'c', print_char}, {'s', print_string},
		{'%', print_percent},
		{'i', print_int}, {'d', print_int},
		{'b', print_binary}, {'u', print_unsign},
		{'o', print_oct},
		{'x', print_hexadec}, {'X', print_hexa_up},
		{'p', print_ptr},
		{'S', non_printableable},
		{'r', print_reverse},
		{'R', print_rot13},
		{'\0', NULL}
	};
	for (i = 0; format_types[i].format != '\0'; i++)
		if (format[*ind] == format_types[i].format)
			return (format_types[i].fn(list, buffer, flags, width, precision, size));

	if (format_types[i].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &format[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}

