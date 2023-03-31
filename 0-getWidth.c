#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
    int curentVal;
    int w = 0;

    for (curentVal = *i + 1; format[curentVal] != '\0'; curentVal++)
    {
        if (is_digit(format[curentVal]))
        {
            w *= 10;
            w += format[curentVal] - '0';
        }
        else if (format[curentVal] == '*')
        {
            curentVal++;
            w = va_arg(list, int);
            break;
        }
        else
            break;
    }

    *i = curentVal - 1;

    return (w);
}
