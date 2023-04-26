#include "shell.h"

/**
 * _strncpy - a function that copy another string
 * @dest: the first string
 * @src: the second string
 * @n: the number of bytes
 * Return: dest
 */

char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}


/**
 * _strcspn - a function that gets segment of a string
 * @s: the first string
 * @reject: the second string
 * Return: count
 */


size_t _strcspn(const char *s, const char *reject)
{
	const char *p;
	const char *r;
	size_t count = 0;

	for (p = s; *p != '\0'; p++)
	{
		for (r = reject; *r != '\0'; r++)
		{
			if (*p == *r)
			{
				return (count);
			}
		}
		count++;
	}
	return (count);
}

/**
 * _strspn - a function that get first segment of a strng in another
 * @s: the first string
 * @accept: the second string
 * Return: count
 */

size_t _strspn(const char *s, const char *accept)
{
	const char *p;
	const char *a;
	size_t count = 0;

	for (p = s; *p != '\0'; p++)
	{
		for (a = accept; *a != '\0'; a++)
		{
			if (*p == *a)
			{
				count++;
				break;
			}
		}
		if (*a == '\0')
		{
			break;
		}
	}
	return (count);
}



/**
 * _strncmp - a function that compares strings
 * @s1: the first string
 * @s2: the second string
 * @n: the bytes to  compare
 * Return: 0
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; ++i)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}

/**
 * _strtok - a function that tokenizes array of strings
 * @s: the string to tokenize
 * @dlim: the delimeter
 * Return: Token
 */

char *_strtok(char *s, const char *dlim)
{
	static char *iter;
	char *token = NULL;
	char *end;

	iter = NULL;
	if (s == NULL)
		s = iter;
	if (s == NULL)
		return (NULL);

	s += _strspn(s, dlim);
	if (*s == '\0')
	{
		return (NULL);
	}
	end = s + _strcspn(s, dlim);

	if (end > s)
	{
		token = malloc(end - s + 1);
		_strncpy(token, s, end - s);
		token[end - s] = '\0';
	}
	iter = end;
	return (token);
}

/**
 * _strlen - a function that gets the length of a string
 * @str: the string to get length
 * Return: len (length of string)
 */

size_t _strlen(const char *str)
{
	size_t len = 0;

	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}


/**
 * _strcpy - a function that copy a string to another
 * @dest: the destination for copying
 * @src: the source for copying
 * Return: dest
 */

char *_strcpy(char *dest, const char *src)
{
	while ((*dest++ = *src++))
		;
	return (dest);
}

/**
 * _strcat - a function that appends a string to another string
 * @dest: the destination of the string
 * @src: the source of the string
 * Return: dest
 */

char *_strcat(char *dest, const char *src)
{
	while (*dest)
		dest++;
	while ((*dest++ = *src++))
		;
	return (dest);
}

/**
 * _strcmp - a function that compares two strings
 * @s1: the first string
 * @s2: the second string
 * Return: an integer to tell if the string are the same or different
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
