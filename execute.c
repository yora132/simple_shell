#include "shell.h"

/**
 * execute - execute a command
 * @argv:arry of string
 * Return:nothing
 */

void execute(char **argv)
{
	char *comand = NULL, *real_comand = NULL;

	if (argv)
	{
		comand = argv[0];

		real_comand = get_path(comand);

		if (execve(real_comand, argv, NULL) == -1)
		{
			perror("Error:");
		};
	}
}
