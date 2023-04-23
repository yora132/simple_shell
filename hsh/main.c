#include "shell.h"


int main(int ac, char **argv)
{
	char *prompt = "(hsh) $";
	char *lineptr;
	size_t n = 0;
	(void)ac; (void)argv;

	while (1)
	{
	printf("%s", prompt);
	if (getline(&lineptr, &n, stdin) == -1)
	{
		return (-1);
	}
	printf("%s\n", lineptr);
	free(lineptr);
	lineptr = NULL;
	n = 0;
	}
	return (0);
}
