#include "shell.h"

/**
 * char *str_cpy - bla bla
 * @dest: bla bla
 * @src: bla bla
 * Return: bla bla
 */

char *str_cpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for (; x < l; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}
