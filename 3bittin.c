#include "shell.h"

/**
 * h_built_in - function
 * @command: variable
 * @av: variable
 * @idx: variable
 * @status: variable
 * Return: int
 */

int h_built_in(char **command, char **av, int idx, int status)
{
	if (_strcmp(command[0], "cd") == 0)
	{
		cd_f(command);
		return (0);
	}
	else if (_strcmp(command[0], "exit") == 0)
	{
		exit_(command, status);
	}
	else if (_strcmp(command[0], "env") == 0)
	{
		env_f(command);
		return (0);
	}
	return (execute(command, av, idx));
}
