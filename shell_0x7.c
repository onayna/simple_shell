#include "shell.h"

/**
 * execute_command - Executes a command in a child process and waits for its completion
 * @args: Array of arguments for the command
 */
void execute_command(char *args[]) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        /* Child process */
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        /* Parent process */
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            /* Child process exited normally */
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            /* Child process terminated by a signal */
            printf("Child process terminated by signal %d\n", WTERMSIG(status));
        }
    }
}

/**
 * parse_input - Parses input into arguments
 * @input: Input string to be parsed
 * @args: Array to store the resulting arguments
 * Return: Number of arguments
 */
int parse_input(char *input, char *args[]) {
    int arg_count = 0;
    char *token = input;

    /* Find the first space or the end of the string */
    while (*token != ' ' && *token != '\0') {
        token++;
    }

    while (*token != '\0') {
        /* Replace the space with a null terminator to separate the argument */
        *token = '\0';

        /* Move to the next character after the null terminator */
        token++;

        /* Find the next non-space character */
        while (*token == ' ') {
            token++;
        }

        /* If the token is not an empty string, add it to the arguments */
        if (*token != '\0') {
            args[arg_count++] = token;
        }

        /* Find the next space or the end of the string */
        while (*token != ' ' && *token != '\0') {
            token++;
        }
    }

    return arg_count;
}

/**
 * main - Entry point of the program
 * Return: Always 0 (success)
 */
int main(void) {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_INPUT_SIZE];

    while (1) {
        int arg_count;

        /* Prompt for input */
        printf(":~$ ");
        fgets(input, sizeof(input), stdin);

        /* Remove the trailing newline character */
        input[strcspn(input, "\n")] = '\0';

        /* Exit if the user enters "exit" */
        if (strcmp(input, "exit") == 0) {
            printf("Exiting the shell\n");
            break;
        }

        /* Parse the input into arguments */
        arg_count = parse_input(input, args);

        /* Execute the command if there are arguments */
        if (arg_count > 0) {
            args[arg_count] = NULL;  /* Null-terminate the array */
            execute_command(args);
        }
    }

    return 0;
}
