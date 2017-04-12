#include <unistd.h>
#include "header.h"

/**
 * _putchar - writes a character to stdout.
 * @c: Character to write to stdout.
 *
 * Return: Bytes written to stdout.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
