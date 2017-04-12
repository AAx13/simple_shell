#include "header.h"

/**
 * _atoi - function to turn the ascii representation of a number into an integer
 * @str: The string we want to turn into an integer.
 *
 * Return: An integer.
 */
int _atoi(char *str)
{
	int i;
	int num;

	for (i = 0; str[i]; i++)
	{
		if (i == 0)
		{
			num = str[i] - 48;
		}
		else
		{
			num = num * 10 + (str[i] - 48);
		}
	}
	return (num);
}
