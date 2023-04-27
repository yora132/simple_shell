#include "shell.h"

/**
 * execute - execute a command
 * @argv:arry of string
 * Return:nothing
 */

void execute(char **argv, char **envp)
{
	char *comand = NULL, *real_comand = NULL;
	pid_t pid;
	int status;

	if (argv)
	{
		comand = argv[0];
		if (strcmp(comand, "cd") == 0)
		{
			return;
		}
		else if (strcmp(comand, "env") == 0)
		{
			return;
		}
		else
		{
			pid = fork();
			if (pid == 0)
			{
				real_comand = get_path(comand);

				if (execve(real_comand, argv, envp) == -1)
				{
					perror("Error:");
				};
			}
			else
			{
				wait(&status);
				/*exit_status = WIFEXITED(status) ? WEXITSTATUS(status) : 0;*/
			}
		}
	}
}
