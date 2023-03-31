#include "main.h"

/**
 * print_ptr - Function for printing pointer
 * @types: variable for argument list
 * @buffer: variable for buffer
 * @flags:  variable for flags calculation
 * @width: gvariable for the width
 * @precision: Precision specification
 * @size: variable for size
 * Return: intger type
 */

int print_ptr(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char ext_c = 0, pad = ' ';
	int ind = BUFF_SIZE - 2, len = 2, pad_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (flags & F_PLUS)
		ext_c = '+', len++;
	else if (flags & F_SPACE)
		ext_c = ' ', len++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_ptr(buffer, ind, length,
		width, flags, pad, ext_c, pad_start));
}

/**
 * non_printable - Function for unsigned specifier
 * @types: variable for argument list
 * @buffer: variable for buffer
 * @flags:  variable for flags calculation
 * @width: gvariable for the width
 * @precision: Precision specification
 * @size: variable for size
 * Return: intger type
 */
int non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = 0, offset = 0;
	char *s = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[a] != '\0')
	{
		if (is_printable(s[a]))
			buffer[a + offset] = s[a];
		else
			offset += append_hexa_code(s[a], buffer, a + offset);

		a++;
	}

	buffer[a + offset] = '\0';

	return (write(1, buffer, a + offset));
}

/**
 * print_reverse - Function for reverse order
 * @types: variable for argument list
 * @buffer: variable for buffer
 * @flags:  variable for flags calculation
 * @width: gvariable for the width
 * @precision: Precision specification
 * @size: variable for size
 * Return: intger type
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *s;
	int a, index = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	s = va_arg(types, char *);

	if (s == NULL)
	{
		UNUSED(precision);

		s = ")Null(";
	}
	for (a = 0; s[a]; a++)
		;

	for (a = a - 1; a >= 0; a--)
	{
		char z = s[a];

		write(1, &z, 1);
		index++;
	}
	return (index);
}

/**
 * print_rot13 - Function for rot 13
 * @types: variable for argument list
 * @buffer: variable for buffer
 * @flags:  variable for flags calculation
 * @width: gvariable for the width
 * @precision: Precision specification
 * @size: variable for size
 * Return: intger type
 */
int print_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char ch;
	char *str;
	unsigned int i, j;
	int index = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				ch = out[j];
				write(1, &ch, 1);
				index++;
				break;
			}
		}
		if (!in[j])
		{
			ch = str[i];
			write(1, &ch, 1);
			index++;
		}
	}
	return (index);
}
