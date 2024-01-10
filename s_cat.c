#include "shell.h"

/**
 * s_cat - function
 * @dest: variable
 * @src: variable
 * Return: char
*/

char *s_cat(char *dest, const char *src)
{
	char *originalDest = dest;

	while (*dest)
	{
		dest++;
	}

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (originalDest);
}
