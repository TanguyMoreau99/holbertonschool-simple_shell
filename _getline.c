#include "main.h"

/**
* _getline - Read the line and might display the prompt
*
* Return: the line.
*/
char *_getline(void) /* Read the line and might display the prompt*/
{
	char *line = NULL;

	size_t line_size = 0;
/* Check if the file descriptor is associated with a terminal*/
	if (isatty(STDIN_FILENO))
	{
		prompt();
	}

	if (getline(&line, &line_size, stdin) == -1) /* Read the line*/
	{
		free(line);
		return (NULL);
	}
	return (line);
}
