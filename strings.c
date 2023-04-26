#include "shell.h"



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
