#include "shell.h"

/**
 * cd_f - function
 * @command: variable
 * Return: void
 */

void cd_f(char **command)
{
	char cwd[1024];

	if ((command[1] == NULL) || (_strcmp(command[1], "~") == 0))
	{
		if (chdir(getenv("HOME")) != 0)
			perror("chdir");
	}
	else if (_strcmp(command[1], "-") == 0)
	{
		char *p_dir = getenv("OLDPWD");

		if (p_dir == NULL)
			fprintf(stderr, "OLDPWD not set\n");
		else
		{
			if (chdir(p_dir) != 0)
				perror("chdir");
		}
	}
	else
	{
		if (chdir(command[1]) != 0)
			perror("chdir");
	}

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		setenv("PWD", cwd, 1);
	else
		perror("getcwd");
	freearr(command);
}
