#include "shell.h"

/**
 * _getenv - a function that gets environment
 * @name: the environment name
 * Return: NULL
 */

char *_getenv(const char *name)
{
	char **p;
	size_t len = strlen(name);

	for (p = environ; *p != NULL; ++p)
	{
		if (_strncmp(*p, name, len) == 0 && (*p)[len] == '=')
		{
			return (&((*p)[len + 1]));
		}
	}

	return (NULL);
}
