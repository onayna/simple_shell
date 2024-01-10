#include "shell.h"

/**
 * print_numbers - Prints even and odd numbers
 */
void print_numbers(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			printf("%d is even\n", i);
		}
		else
		{
			printf("%d is odd\n", i);
		}
	}
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	print_numbers();
	return (0);
}
