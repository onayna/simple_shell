#include "shell.h"
/**
 * _getApTH - Searches for the full path of a command
 * @inputcommand:command to search for
 * Return: pointer to the full path if found otherwise NULL
 */
char *_getApTH(const char *inputcommand)
{
char *PENVTH, *FCDM, *D;
struct stat st;
int i = 0;

while (inputcommand && inputcommand[i])
{
if (inputcommand[i] == '/')
{
if (stat(inputcommand, &st) == 0)
{
return (s_dup(inputcommand));
}
return (NULL);
}
i++;
}
PENVTH = my_getenv("PATH");
if (!PENVTH)
return (NULL);
D = strtok(PENVTH, ":");
while (D)
{
FCDM = malloc(_strlen(D) + _strlen(inputcommand) + 2);
if (FCDM)
{
s_cpy(FCDM, D), s_cat(FCDM, "/"), s_cat(FCDM, inputcommand);
if (stat(FCDM, &st) == 0)
{
free(PENVTH);
return (FCDM);
}
free(FCDM), FCDM = NULL, D = strtok(NULL, ":");
}
}
free(PENVTH);
return (NULL);
}
