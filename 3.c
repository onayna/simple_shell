#include "shell.h"

/**
 * _strlen - bla bla
 * @s: bla bla
 * Return: bla bla
 */

int _strlen(const char *s)
{
	int longi = 0;

	if (!s)
		return (0);
	while (*s != '\0')
	{
		longi++;
		s++;
	}
	return (longi);
}
