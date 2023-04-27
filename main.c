#include "shell.h"

/*int exit_status = 0;*/
/**
 * main - entry of the shell
 * @ac:number of arguments
 * @argv:array of arguments
 * @envp:enviornment variable
 * Return:0 in sucsse
 */

int main(int ac, char **argv, char **envp)
{
	char *prompt = "#cisfun$ ";
	char *lineptr;
	ssize_t num_chars;
	const char *delim = " \n";
	size_t n = 0;
	(void)ac;

	while (1)
	{
	printf("%s", prompt);
	num_chars = getline(&lineptr, &n, stdin);
	if (num_chars == -1)
	{
		return (-1);
	}
	/*printf("%s\n", lineptr);*/
	argv = tokenize(lineptr, delim, num_chars);
	execute(argv, envp);
	free(lineptr);
	lineptr = NULL;
	n = 0;
	}
	return (0);
}
