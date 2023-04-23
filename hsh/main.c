#include "shell.h"


int main(int ac, char **argv)
{
	char *prompt = "(hsh) $";
	char *lineptr;
	ssize_t num_chars;
	const char delim = " \n";
	size_t n = 0;
	(void)ac; (void)argv;

	while (1)
	{
	printf("%s", prompt);
	num_chars = getline(&lineptr, &n, stdin);
	if (num_chars == -1)
	{
		return (-1);
	}
	printf("%s\n", lineptr);
	argv = tokenize(lineptr, delim, num_chars);
	free(lineptr);
	lineptr = NULL;
	n = 0;
	}
	return (0);
}
