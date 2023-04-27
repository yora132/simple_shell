#ifndef SHELL_H_
#define SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

char **tokenize(char *str, const char *delim, ssize_t num_chars);
void execute(char **argv, char **envp);
char *get_path(char *comand);
void env_function(char **arg);
void set_env(char **arg);
void unset_env(char **arg);
#endif
