#include "shell.h"

/**
 * display_shell_prompt - Display the shell prompt.
 */
void display_shell_prompt(void)
{
    printf(":~$ ");
    fflush(stdout);
}

/**
 * read_user_command - Read the user input command.
 * @user_input: Buffer to store the input.
 */
void read_user_command(char *user_input)
{
    if (fgets(user_input, BUFFER_SIZE, stdin) == NULL)
    {
        printf("\n");
        exit(EXIT_SUCCESS);
    }
    user_input[strcspn(user_input, "\n")] = '\0';
}

/**
 * execute_user_command - Execute the provided command with its arguments.
 * @command_arguments: Array of command and its arguments.
 */
void execute_user_command(char *command_arguments[])
{
    int status;
    pid_t pid = fork();

    if (pid == 0)
    {
        if (execvp(command_arguments[0], command_arguments) == -1)
        {
            perror("shell_0x0");
 }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("shell_0x0");
    }
    else
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

/**
 * main - Entry point for the shell program.
 * Return: Always 0.
 */
int main(void)
{
    char user_input[BUFFER_SIZE];
    char *command_arguments[MAX_ARGS];
    int arg_index;
 while (1)
    {
        display_shell_prompt();
        read_user_command(user_input);

        command_arguments[0] = strtok(user_input, " ");
        if (!command_arguments[0]) continue;

        arg_index = 1;
        while ((command_arguments[arg_index] = strtok(NULL, " ")) != NULL && arg_index < MAX_ARGS - 1)
            arg_index++;

        command_arguments[arg_index] = NULL;

        execute_user_command(command_arguments);
    }

    return (0);
}
