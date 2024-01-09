rtok(NULL, " \t\n");
    }

    args[arg_count] = NULL;
}

/**
 * main - Entry point of the program
 * Return: Always 0 (success)
 */
int main(void)
{
    char input[BUFFER_SIZE];
    char *args[MAX_ARGS];

    while (1)
    {
        printf(":~$ ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Error encountered while reading input.\n");
            exit(1);
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "end") == 0)
        {
            break;
        }

        parse_input(input, args);

        if (args[0] != NULL)
        {
            pid_t pid = fork();

            if (pid == 0)
            {
                if (execvp(args[0], args) == -1)
                {
                    printf("Unable to execute: %s\n", args[0]);
                    exit(1);
                }
            }
            else if (pid < 0)
            {
                printf("Failed to create child process.\n");
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
