#include "shell.h"

/**
 * struct Alias - Struct to hold alias name-value pairs
 * @name: The alias name
 * @value: The alias value
 */
typedef struct Alias
{
	char name[MAX_ALIAS_LENGTH];
	char value[MAX_ALIAS_LENGTH];
} Alias;

Alias aliases[MAX_ALIASES];
int numAliases = 0;

/**
 * print_aliases - Print aliases based on provided arguments
 * @args: Array of alias names or NULL
 * @numArgs: Number of arguments in args
 */
void print_aliases(char **args, int numArgs)
{
	int i, j;
	int found = 0;

	if (numArgs == 0)
	{
		for (i = 0; i < numAliases; i++)
		{
			printf("%s='%s'\n", aliases[i].name, aliases[i].value);
		}
	}
	else
	{
		for (i = 0; i < numArgs; i++)
		{
			char *name = args[i];
			found = 0;
			for (j = 0; j < numAliases; j++)
			{
				if (strcmp(name, aliases[j].name) == 0)
				{
					printf("%s='%s'\n", aliases[j].name, aliases[j].value);
					found = 1;
					break;
				}
			}
			if (!found)
			{
				printf("Alias not found: %s\n", name);
			}
		}
	}
}

/**
 * set_alias - Set or update an alias
 * @args: Array of alias definitions
 * @numArgs: Number of alias definitions
 */
void set_alias(char **args, int numArgs)
{
	int i, j;
	int found = 0;

	for (i = 0; i < numArgs; i++)
	{
		char *arg = args[i];
		char *equals = strchr(arg, '=');

		if (equals != NULL)
		{
			char *value = equals + 1;
			int nameLength = equals - arg;
			char name[MAX_ALIAS_LENGTH];
			strncpy(name, arg, nameLength);
			name[nameLength] = '\0';

			found = 0;

			for (j = 0; j < numAliases; j++)
			{
				if (strcmp(name, aliases[j].name) == 0)
				{
					strncpy(aliases[j].value, value, MAX_ALIAS_LENGTH);
					found = 1;
					break;
				}
			}

			if (!found)
			{
				if (numAliases >= MAX_ALIASES)
				{
					printf("Maximum number of aliases reached\n");
					return;
				}

				strcpy(aliases[numAliases].name, name);
				strcpy(aliases[numAliases].value, value);
				numAliases++;
			}
		}
		else
		{
			printf("Invalid alias format: %s\n", arg);
		}
	}
}

/**
 * alias_builtin - Handle the 'alias' built-in command
 * @args: Array of command arguments
 * @numArgs: Number of command arguments
 */
void alias_builtin(char **args, int numArgs)
{
	int i;

	if (numArgs == 0)
	{
		char *aliasNames[MAX_ALIASES];
		for (i = 0; i < numAliases; i++)
		{
			aliasNames[i] = aliases[i].name;
		}
		print_aliases(aliasNames, numAliases);
	}
	else
	{
		if (strcmp(args[0], "-h") == 0 || strcmp(args[0], "--help") == 0)
		{
			printf("Usage: alias [name[='value'] ...]\n");
			printf("alias: Prints a list of all aliases, one per line, in the form name='value'\n");
			printf("alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'\n");
			printf("alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value\n");
		}
		else
		{
			set_alias(args, numArgs);
		}
	}
}

/**
 * main - Entry point of the program
 * Return: Always 0 (SUCCESS)
 */
int main(void)
{
	while (1)
	{
		char user_input[MAX_ALIAS_LENGTH];
		char *args[100];
		char *token;
		int numArgs;

		printf(":~$ ");
		fgets(user_input, sizeof(user_input), stdin);
		user_input[strcspn(user_input, "\n")] = '\0';

		numArgs = 0;
		token = strtok(user_input, " ");

		while (token != NULL)
		{
			args[numArgs] = token;
			numArgs++;
			token = strtok(NULL, " ");
		}

		if (numArgs == 0)
		{
			continue;
		}

		if (strcmp(args[0], "alias") == 0)
		{
			alias_builtin(args + 1, numArgs - 1);
		}
	}

	return (0);
}
