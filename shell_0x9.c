#include "shell.h"

/**
 * set_env_variable - Set an environment variable.
 * @args: Array containing the command and arguments.
 */
void set_env_variable(char **args)
{
	char *variable, *value;

	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return;
	}

	variable = args[1];
	value = args[2];

	if (setenv(variable, value, 1) != 0)
	{
		perror("setenv");
	}
}

/**
 * unset_env_variable - Unset an environment variable.
 * @args: Array containing the command and arguments.
 */
void unset_env_variable(char **args)
{
	char *variable;

	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return;
	}

	variable = args[1];

	if (unsetenv(variable) != 0)
	{
		perror("unsetenv");
	}
}

/**
 * main - Entry Point of Program
 */
int main(void)
{
	char command[100];
	char *args[100];
	char *token;
	int i;

	while (1)
	{
		printf(":~$ ");

		fgets(command, sizeof(command), stdin);
		command[strcspn(command, "\n")] = '\0';

		token = strtok(command, " ");
		i = 0;

		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}

		args[i] = NULL;
		if (args[0] == NULL)
		{
			continue;
		}

		if (strcmp(args[0], "setenv") == 0)
		{
			set_env_variable(args);
		}
		else if (strcmp(args[0], "unsetenv") == 0)
		{
			unset_env_variable(args);
		}
		else
		{
			printf("Unknown command: %s\n", args[0]);
		}
	}

	return (0);
}
