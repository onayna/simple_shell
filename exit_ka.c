#include "shell.h"

/**
 * exit_ - function
 * @command:variable
 * @status: variable
 * Return: void
 */

void exit_(char **command, int status)
{
	int exit_status = 0;

	if (command[1] != NULL)
	{
		exit_status = atoi(command[1]);
	}
	else
		exit_status = status;

	freearr(command);
	exit(exit_status);
}
