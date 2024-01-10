#include "shell.h"
/**
 * readline_aa - bla bla
 *
 * Return: bla bla
 */
char *readline_aa(void)
{
char *BUFLINE = NULL;
size_t SIZEL = 0;
ssize_t RB;

if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
RB = getline(&BUFLINE, &SIZEL, stdin);
if (RB == EOF)
{
free(BUFLINE);
return (NULL);
}
return (BUFLINE);
}
