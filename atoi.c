#include "header.h"

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
