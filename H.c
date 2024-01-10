#include "shell.h"

/**
 * _tokenit_aa - bla bla
 * @command_input: bla bla
 * Return: bla bla
 */

char **_tokenit_aa(char *command_input)
{
	char *token = NULL;
	char **command_output = NULL;
	int counter = 0;

	if (!command_input)
		return (NULL);

	command_output = malloc(sizeof(char *) * 10);

	if (!command_output)
	{
		free(command_input);
		return (NULL);
	}

	token = strtok(command_input, " \t\n");
	while (token)
	{
		command_output[counter++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	free(command_input);

	command_output[counter] = NULL;
	return (command_output);
}
