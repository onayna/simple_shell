#include "shell.h"

/**
 * main - arguments function
 * @ac:count of argumnents
 * @av: arguments arayy
 * Return: the shell program status
 */

int main(int ac, char **av)
{
	Da_ta_s Dat_a;

	Dat_a.line_buff = NULL;
	Dat_a.input = NULL;
	Dat_a.status = 0;
	Dat_a.count = 0;

	(void)ac;

	while (true)
	{
		Dat_a.line_buff = read_line_aa();
		if (!Dat_a.line_buff)
		{
			if (isatty(2))
				write(2, "\n", 1);
			return (Dat_a.status);
		}

		Dat_a.count++;
		Dat_a.input = _tokenit(Dat_a.line_buff);
		if (Dat_a.input)
			Dat_a.status = h_built_in(Dat_a.input, av, Dat_a.count, Dat_a.status);
	}
}
