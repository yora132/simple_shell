#include "shell.h"

/**
 * execute - execute a command
 * @argv:arry of string
 * @envp: the enviroment variable
 * Return:nothing
 */

void execute(char **argv, char **envp)
{
	char *comand = NULL, *real_comand = NULL;

	if (argv)
	{
		comand = argv[0];
		if (strcmp(comand, "cd") == 0)
		{
			return;
		}
		else if (strcmp(comand, "env") == 0)
		{
			env_function(argv);
			return;
		}
		else if (strcmp(comand, "setenv") == 0)
		{
			set_env(argv);
			return;
		}
		else if (strcmp(comand, "unsetenv") == 0)
		{
			unset_env(argv);
			return;
		}
		else
		{
			real_comand = get_path(comand);

			if (execve(real_comand, argv, envp) == -1)
			{
				fprintf(stderr, "./hsh: No such file or directory\n");
			};
		}

	}
}
