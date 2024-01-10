#include "shell.h"

/**
 * _itoa_aa - bla bla
 * @num: bla bla
 * @str: bla bla
 * @base: bla bla
 * Return: bla bla
*/

char *_itoa_aa(int num, char *str, int base)
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
