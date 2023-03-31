#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
    int currentVal = *i + 1;
    int size_ = 0;

    if (format[currentVal] == 'l')
        size_ = S_LONG;
    else if (format[currentVal] == 'h')
        size_ = S_SHORT;

    if (size_ == 0)
        *i = currentVal - 1;
    else
        *i = currentVal;

    return (size_);
}
