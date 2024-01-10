#include "shell.h"

/**
 * char *s_cpy - copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */

char *s_cpy(char *dest, char *src)
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
