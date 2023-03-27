#include "main.h"

/**
 * char_write - function to wite character
 * @ch: variable for character to be printed
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int char_write(char ch)
{
	return (write(1, &ch, 1));
}
