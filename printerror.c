#include "shell.h"

/**
 * printerror - function
 * @name: var
 * @cmd: var
 * @idx: var
 * Return: void
*/

void printerror(const char *name, const char *cmd, int idx)
{
	const char *index;
	char idx_str[20];

	_itoa(idx, idx_str, 10);
	index = idx_str;

	PRINT_ERROR(name, index, cmd);
}
