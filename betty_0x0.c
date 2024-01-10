#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int number1, number2, sum;

	number1 = 10;
	number2 = 20;

	sum = number1 + number2;

	printf("The sum of %d and %d is: %d\n", number1, number2, sum);

	return (0);
}
