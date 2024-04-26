#include "main.h"

/**
 * _strtok - function that split line to arguments
 * @line: array of char
 * Return: the pointer args
*/

char **_strtok(char *line) /* Split the line to arguments*/
{
	char *token = NULL;
	char **args = NULL;
	int size = 64;
	int token_index = 0;

	if (line == NULL)
	{
		return (NULL);
	}

	args = malloc((size + 2) * sizeof(char *));
	if (args == NULL)
		return (NULL);

	token = strtok(line, " \r\t\n");/*Tokenieze the input line*/

	while (token != NULL)
	{
		args[token_index] = token; /* store each token in the args array*/
		token_index++;
		if (token_index >= size)
		{
			size += size;
			args = realloc(args, size * sizeof(char *));
			if (args == NULL)
				return (NULL);
		}
		token = strtok(NULL, " \t\r\n");/* Get the next token*/
	}

	args[token_index] = NULL;
	return (args);
}
