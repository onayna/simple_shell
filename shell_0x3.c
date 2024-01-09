#include "shell.h"

void tokenize(char *input, char *tokens[MAX_TOKENS]);

/**
 * main - Entry Point for shell program
 *
 * Return : Always 0 (success)
 *
 * Description : Shell Program with C
 */
int main(void)
{
    char input[MAX_INPUT];
    char *tokens[MAX_TOKENS];

    while (1)
    {
        printf(":~$ ");
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Error reading input.\n");
            exit(1);
        }

        if (input[strlen(input) - 1] == '\n')
        {
            input[strlen(input) - 1] = '\0';
        }

        if (strcmp(input, "exit") == 0)
        {
            break;
        }

        tokenize(input, tokens);

        if (tokens[0] != NULL)
        {
            pid_t pid = fork();

            if (pid == 0)
            {
                if (execvp(tokens[0], tokens) == -1)
                {
                    printf("Command not found: %s\n", tokens[0]);
                    exit(1);
                }
            }
            else if (pid < 0)
            {
                printf("Fork failed.\n");
                exit(1);
            }
            else
            {
                int status;
                waitpid(pid, &status, 0);
            }
        }
    }

    return 0;
}

/**
 * tokenize - Tokenize a string into words
 *
 * @input: User input string
 * @tokens: An array to store the resulting tokens
 */
void tokenize(char *input, char *tokens[MAX_TOKENS])
{
    char *token = strtok(input, " \t\n");
    int token_count = 0;

    while (token != NULL)
    {
        tokens[token_count] = token;
        token_count++;

        token = strtok(NULL, " \t\n");
    }

    tokens[token_count] = NULL;
}
