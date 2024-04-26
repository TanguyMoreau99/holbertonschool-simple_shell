#include "main.h"
/**
 * print_env - display the environment
 * @token: pointer
 * Return: 0
*/
int print_env(char **token)
{
	size_t env_index = 0;

		if (*token)
		{
			while (environ[env_index]) /* print the environment*/
			{
				if (printf("%s\n", environ[env_index]) == -1)
				{
					perror("Error");
					return (1);
				}
				env_index++;
			}
		}
		return (0);
	}
