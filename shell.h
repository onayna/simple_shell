#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>

/**
 * struct Da_ta_s - bla bla
 * @line_buff: bla bla
 * @input: bla bla
 * @status: bla bla
 * @count: bla bla
 */

typedef struct Da_ta_s
{
	char *line_buff;
	char **input;
	int status;
	int count;
} Da_ta_s;

/**
 * struct EGETENV - bla bla
 * @tmp: bla bla
 * @key: bla bla
 * @value: bla bla
 * @env: bla bla
 * @i: bla bla
 */

typedef struct EGETENV
{
	char *tmp;
	char *key;
	char *value;
	char *env;
	int i;
} EGETENV;

#define PRINT_ERROR(name, index, cmd)\
	do {\
		write(STDERR_FILENO, name, _strlen(name));\
		write(STDERR_FILENO, ": ", 2);\
		write(STDERR_FILENO, index, _strlen(index));\
		write(STDERR_FILENO, ": ", 2);\
		write(STDERR_FILENO, cmd, _strlen(cmd));\
		write(STDERR_FILENO, " not found \n", _strlen(" not found\n") + 1);\
	} while (0)

#define TNNEW_LINE " \t\n"

char *readline_aa(void);
char **_tokenit_aa(char *command_input);
char *s_dup_aa(const char *str);
int _strcmp_aa(const char *s1, const char *s2);
int execute_aa(char **command, char **av, int idx);
void freearr_aa(char **ar);

char *my_getenv_aa(char *vari);
void printerror_aa(const char *name, const char *cmd, int idx);
char *_getApTH(const char *command);
char *s_cat_aa(char *dest, const char *src);
int _strlen(const char *s);
void reverse(char str[], int length);
char *_itoa_aa(int num, char *str, int base);
int h_built_in_aa(char **command, char **av, int idx, int status);
char *str_cpy(char *dest, char *src);
extern char **environ;

void cd_fun(char **command);
void exit_aa(char **command, int status);
void env_fun(char **command);

#endif /*SHELL_H*/
