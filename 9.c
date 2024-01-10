#include "shell.h"
/**
 * freearr_aa - bla bla
 * @ar: bla bla
 * Return: bla bla
*/
void freearr_aa(char **ar)
{
	int k;

	for (k = 0; ar[k] != NULL; k++)
	{
		free(ar[k]);
		ar[k] = NULL;
	}
	free(ar);
}
/**
 * reverse - bla bla
 * @str: bla bla
 * @length: bla bla
 * Return: bla bla
*/
void reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
