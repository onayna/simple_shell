#include "shell.h"

/**
 * execute_command - Executes a given command
 * @command: The command to execute
 *
 * Return: 1 on success, 0 on failure
 */
int execute_command(char *command)
{
        int status = system(command);

        if (status == 0)
                return (1);
        else
                return (0);
}

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
        char user_input[100];
        char *command;
        char *commands[10];
        int command_count = 0;
 int success = 1;
        int i;

        while (1)
        {
                printf(":~$ ");

                fgets(user_input, sizeof(user_input), stdin);

                user_input[strcspn(user_input, "\n")] = '\0';

                if (strcmp(user_input, "exit") == 0)
                        break;


                command = strtok(user_input, "&&");

                while (command != NULL)
                {
                        commands[command_count] = command;
                        command_count++;
                        command = strtok(NULL, "&&");
                }
                for (i = 0; i < command_count; i++)
                {
                        if (!execute_command(commands[i]))
 {
                                success = 0;
                                break;
                        }
                }

                if (!success)
                {
                        command_count = 0;


                        command = strtok(user_input, "||");

                        while (command != NULL)
                        {
                                commands[command_count] = command;
                                command_count++;
                                command = strtok(NULL, "||");
                        }

                        success = 0;


                        for (i = 0; i < command_count; i++)
                        {
 if (execute_command(commands[i]))
                                {
                                        success = 1;
                                        break;
                                }
                        }
                }

                if (!success)
                        printf("Command failed\n");
        }

        return (0);
}

