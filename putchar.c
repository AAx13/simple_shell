#include <unistd.h>
#include "header.h"


int _putchar(char c)
{
	return (write(1, &c, 1));
}
