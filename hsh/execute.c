#include "shell.h"

/**
 * execute - execute a command
 * @argv:arry of string
 * Return:nothing
 */

void execute(char **argv)
{
	char *comand = NULL;

	if (argv)
	{
		comand = argv[0];

		if (execve(comand, argv, NULL) == -1)
		{
			perror("Error:");
		};
	}
}
