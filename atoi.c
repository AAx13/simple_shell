#include "header.h"

/**
 * _atoi - function to turn an ascii representation of a number into an integer
 * @str: The string we want to turn into an integer.
 *
 * Return: An integer.
 */
int _atoi(char *str)
{
	int i;
	int num, sentinel;

	sentinel = 0;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-')
		{
			i++;
			sentinel++;
		}

		if (str[i] > 47 && str[i] < 58)
		{

			if (i == 0 || (i == 1 && sentinel > 0))
			{
				num = str[i] - 48;
			}
			else
			{
				num = num * 10 + (str[i] - 48);
			}
		}
		else
		{
			return (1);
		}
	}
	if (sentinel > 0)
	{
		num *= -1;
	}

	return (num);
}
