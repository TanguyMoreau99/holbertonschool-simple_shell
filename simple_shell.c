#include "main.h"

/**
 * main - entry point
 * @argv: arguments in the stdin
 * @argc: numbers of arguments
 *
 * Return: 0 for success.
*/

int main(int argc, char **argv)
{
	char *line = NULL;
	char **tokens;
	int status = 0, pathnumb = 0;
	(void)argc;

	while (1)
	{
		errno = 0;

		line = _getline();/*read a line of input from the user*/
		if (line == NULL && errno == 0)
		{
			exit(1);
		}
		if (line) /* INput line isn't empty*/
		{
			pathnumb++;
			tokens = _strtok(line);
			if (tokens == NULL)
				free(line);
			status = exec(tokens, argv, pathnumb);
			free(tokens);
			free(line);
			if (status == 42)
			{
				printf("Exited normally.\n");
				exit(0);
			}
		}
		else /* input line empty*/
		{
			if (isatty(STDIN_FILENO)) /* Chech if stdout is a terminal*/
			{
				printf("\n");
			}
			printf("Exited with status: %d\n", WEXITSTATUS(status));
			exit(status);
		}
	}
	exit(status);
}
