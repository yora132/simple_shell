#include "shell.h"

/**
 * get_path - detirmaine the path of command
 * @comand:the command to be written
 * Return:the path
 */

char *get_path(char *comand)
{
	char *path, *path_copy, *path_token, *file_path;
	int comand_len, dir_len;
	struct stat buff;

	path = getenv("PATH");
	if (path)
	{	path_copy = strdup(path);
		comand_len = strlen(comand);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{dir_len = strlen(path_token);
			file_path = malloc(comand_len + dir_len + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, comand);
			strcat(file_path, "\0");
			if (stat(file_path, &buff) == 0)
			{free(path_copy);
				return (file_path);
			}
			else
			{free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(comand, &buff) == 0)
		{return (comand);
		}
		return (NULL);
	}
	return (NULL);
}
