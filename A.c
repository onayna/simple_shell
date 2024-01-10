#include "shell.h"

/**
 * my_getenv_aa - bla bla
 * @vari:bla bla
 * Return: bla bla
 */

char *my_getenv_aa(char *vari)
{
	EGETENV ENV;

	for (ENV.i = 0; environ[ENV.i]; ENV.i++)
	{
		ENV.tmp = s_dup_aa(environ[ENV.i]);
		ENV.key = strtok(ENV.tmp, "=");

		if (_strcmp_aa(ENV.key, vari) == 0)
		{
			ENV.value = strtok(NULL, "\n");
			ENV.env = s_dup_aa(ENV.value);

			free(ENV.tmp);
			return (ENV.env);
		}

		free(ENV.tmp), ENV.tmp = NULL;
	}

	return (NULL);
}
