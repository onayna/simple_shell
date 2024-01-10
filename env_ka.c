#include "shell.h"

/**
 * env_f - function
 * @command:variable
 * Return: void
 */

void env_f(char **command)
{
	char **env = environ;

		while (*env != NULL)
		{
			write(STDOUT_FILENO, *env, strlen(*env));
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
		freearr(command);
}
