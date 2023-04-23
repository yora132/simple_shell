#include "shell.h"
/**
 * tokenize - splits the command into words
 * @str: the command input
 * @delim: the delimeter that sperates the words
 * @num_chars: number of characters
 * Return: array of splitted words
 */
char **tokenize(char *str, const char *delim, ssize_t num_chars)
{
	char *lineptr_copy = NULL;
	char *token;
	char **argv;
	int num_tokens = 0;
	int i = 0;

	lineptr_copy = malloc(sizeof(char) * num_chars);
	strcpy(lineptr_copy, str);
	token = strtok(str, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_token++;
	argv = malloc(sizeof(char *) * num_tokens);
	token = strtok(lineptr_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(lineptr_copy);
	return (argv);
}
