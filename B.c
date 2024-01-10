#include "shell.h"

/**
 * printerror_aa - bla bla
 * @name:bla bla
 * @cmd: bla bla
 * @idx: bla bla
 * Return: bla bla
*/

void printerror_aa(const char *name, const char *cmd, int idx)
{
	const char *index;
	char idx_str[20];

	_itoa_aa(idx, idx_str, 10);
	index = idx_str;

	PRINT_ERROR(name, index, cmd);
}
