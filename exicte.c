#include "shell.h"

/**
 * execute - function
 * @command:variable
 * @av: variable
 * @idx:variable
 * Return: int
 */

int execute(char **command, char **av, int idx)
{
	pid_t child;
	int status;
	char *full_cmd;

	full_cmd = _getApTH(command[0]);
	if (!command || !command[0] || !command[0][0])
	{
		freearr(command);
		free(full_cmd);
		return (0);
	}
	if (!full_cmd)
	{
		printerror(av[0], command[0], idx);
		freearr(command);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			perror(av[0]);
			freearr(command);
			free(full_cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearr(command);
		free(full_cmd);
	}
	return (WEXITSTATUS(status));
}
