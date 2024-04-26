#include "main.h"

/**
 * exec - function that execute
 *
 * @token: ppointer from _strtok
 * @argv: argument
 * @path: path ID
 * 
 * Return: 0;
 */
int exec(char **token, char **argv, int path)
{
    pid_t pid;
    int status, built;
    char *phraze = "%s: %d: %s: command not found\n";
    char **env = environ;
    char *paths = NULL;

    if (token[0] == NULL) /* If token is empty*/
    {
        return (0);
    }
    
    built = builtin(token); /* Check if the command is a built-in command*/
    if (built != 0)
    {
        return (built);
    }

    while (*env != NULL) /* Check if the command is in the PATH*/
    {
        if (strncmp(*env, "PATH=", 5) == 0)
        {
            paths = *env + 5;
            break;
        }
        env++;
    }
    pid = fork();
    if (pid == 0)
    {
        if (execve(token[0], token, environ) == -1)
        {
            if (paths != NULL)
            {
                paths = strtok(paths, ":");
                while (paths != NULL) /* Check if the command is in the PATH*/
                {
                    char *full_path = malloc(strlen(paths) + 1 + strlen(token[0]) + 1);
                    if (full_path == NULL)
                    {
						free(full_path);
                        exit(1);
                    }
                    strcpy(full_path, paths);
                    strcat(full_path, "/");
                    strcat(full_path, token[0]);
                    if (access(full_path, X_OK) == 0) /* Check if the command is executable*/
                    {
                        if (execve(full_path, token, environ) == -1)
                        {
							free(full_path);
                            exit(1);
                        }
                    }
                    paths = strtok(NULL, ":"); /* Check the next path*/
                    free(full_path);
                }
            }

            fprintf(stderr, phraze, argv[0], path, token[0]); /* Print error message*/
            free(token);
            exit(127);
        }
    }
    else
    {
        wait(&status);
        return (status);
    }
    return (0);
}
