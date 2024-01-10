#include "shell.h"

/**
 * h_built_in_aa - bla bla
 * @command: bla bla
 * @av: bla bla
 * @idx: bla bla
 * @status: bla bla
 * Return: bla bla
 */

int h_built_in_aa(char **command, char **av, int idx, int status)
{
	if (_strcmp_aa(command[0], "cd") == 0)
	{
		cd_fun(command);
		return (0);
	}
	else if (_strcmp_aa(command[0], "exit") == 0)
	{
		exit_aa(command, status);
	}
	else if (_strcmp_aa(command[0], "env") == 0)
	{
		env_fun(command);
		return (0);
	}
	return (execute_aa(command, av, idx));
}
