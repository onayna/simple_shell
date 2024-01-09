#include "shell.h"

/**
 * run_command - Executes a command using the system function
 * @cmd: Command to be executed
 * Return: 1 if the command is executed successfully, 0 otherwise
 */
int run_command(char *cmd) {
    int status = system(cmd);
    return WEXITSTATUS(status) == 0;
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[]) {
    FILE *file;
    char command[MAX_COMMAND_LENGTH];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(command, sizeof(command), file) != NULL) {
        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }
        run_command(command);
    }

    fclose(file);
    return 0;
}
