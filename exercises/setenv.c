#include <stdlib.h>
#include "header.h"

int setenv(const char *name, const char *value, int overwrite)
{
	char *old_value;

	old_value = _getpath(name);
	/* =/blah/blah/ */

	if (overwrite > 0)
	{
		if (_strcmp(
	}
}
