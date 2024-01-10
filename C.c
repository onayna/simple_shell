#include "shell.h"
/**
 * _getApTH - bla bla
 * @inputcommand:bla bla
 * Return: bla bla
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
return (s_dup_aa(inputcommand));
}
return (NULL);
}
i++;
}
PENVTH = my_getenv_aa("PATH");
if (!PENVTH)
return (NULL);
D = strtok(PENVTH, ":");
while (D)
{
FCDM = malloc(_strlen(D) + _strlen(inputcommand) + 2);
if (FCDM)
{
str_cpy(FCDM, D), s_cat_aa(FCDM, "/"), s_cat_aa(FCDM, inputcommand);
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
