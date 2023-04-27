#include "shell.h"
/**
 * env_function - function simulate the env command
 * @arg: argument
 * Return: void
 */
void env_function(char **arg)
{
	int i;

	if (arg[0] == NULL)
		fprintf(stderr, "env: %s : No such file or directory\n", arg[1]);
	else
	{
		for (i = 0; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);
	}
}
/**
 * set_env - sets an environment variable
 * @arg: input
 * Return: void
 */
void set_env(char **arg)
{
	char *variable = arg[1];
	char *value;
	int result = 0;

	if (variable != NULL)
	{
		value = arg[2];
		if (value == NULL)
			fprintf(stderr, "Error setting the variable\n");
		else
			result = setenv(variable, value, 1);
	}
	else
		fprintf(stderr, "Error setting the variable\n");
	if (result == -1)
		fprintf(stderr, "Error setting the variable\n");
}
/**
 * unset_env - delets an environment variable
 * @arg: input
 * Return: void
 */
void unset_env(char **arg)
{
	char *variable = arg[1];
	int result;

	result = unsetenv(variable);
	if (result != -1)
		fprintf(stderr, "Error unsetting the variable\n");
}