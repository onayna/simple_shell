#include "shell.h"

/**
 * s_dup - function
 * @str: variable
 * Return: char
*/

char *s_dup(const char *str)
{
	char *k;
	int x, y;

	if (str == NULL)
		return (NULL);

	x = 0;
	while (str[x] != '\0')
		x++;

	k = malloc(sizeof(char) * (x + 1));
	if (k == NULL)
		return (NULL);

	for (y = 0; str[y]; y++)
		k[y] = str[y];
	k[y] = '\0';

	return (k);
}
