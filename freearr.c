#include "shell.h"
/**
 * freearr - finction
 * @ar: var
 * Return: void
*/
void freearr(char **ar)
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
 * reverse - finction
 * @str: var
 * @length: var
 * Return: void
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
