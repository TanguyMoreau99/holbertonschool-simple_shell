#include "main.h"
/**
 * eof - exit program shell
 * @token: token from str_tok
 * Return: return 42
*/

int eof(char **token)
{
	/* exit with status */
	if (token[1])
	{
		return (atoi(token[1]));
	}
	/* exit success */
	else
	{
		return (42);/*signal to exit the simple shell*/
	}
}
