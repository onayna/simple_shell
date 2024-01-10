#include "shell.h"

/**
 * _tokenit - function
 * @command_input: variable
 * Return: char
 */

char **_tokenit(char *command_input)
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
