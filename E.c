#include "shell.h"

/**
 * s_cat_aa - bla bla
 * @dest: bla bla
 * @src: bla bla
 * Return: bla bla
*/

char *s_cat_aa(char *dest, const char *src)
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
