#include "shell.h"

/**
 * env_fun - bla bla
 * @command:bla bla
 * Return: bla bla
 */

void env_fun(char **command)
{
	char **env = environ;

		while (*env != NULL)
		{
			write(STDOUT_FILENO, *env, strlen(*env));
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
		freearr_aa(command);
}
