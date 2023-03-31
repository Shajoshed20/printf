#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int currentVal = *i + 1;
	int exactness = -1;

	if (format[currentVal] != '.')
		return (exactness);

	exactness = 0;

	for (currentVal += 1; format[currentVal] != '\0'; currentVal++)
	{
		if (is_digit(format[currentVal]))
		{
			exactness *= 10;
			exactness += format[currentVal] - '0';
		}
		else if (format[currentVal] == '*')
		{
			currentVal++;
			exactness = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = currentVal - 1;

	return (exactness);
}
