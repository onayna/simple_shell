#include "shell.h"

/**
 * exit_aa - bla bla
 * @command:bla bla
 * @status: bla bla
 * Return: bla bla
 */

void exit_aa(char **command, int status)
{
	int exit_status = 0;

	if (command[1] != NULL)
	{
		exit_status = atoi(command[1]);
	}
	else
		exit_status = status;

	freearr_aa(command);
	exit(exit_status);
}
