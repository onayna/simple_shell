#include "shell.h"

/**
 * _itoa - function
 * @num: var
 * @str: var
 * @base: var
 * Return: char
*/

char *_itoa(int num, char *str, int base)
{
	int i = 0;
	int isNegative = 0;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}

	if (num < 0 && base == 10)
	{
		isNegative = 1;
		num = -num;
	}

	while (num != 0)
	{
		int remainder = num % base;

		str[i++] = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
		num = num / base;
	}

	if (isNegative && base == 10)
	{
		str[i++] = '-';
	}

	str[i] = '\0';
	reverse(str, i);

	return (str);
}
