#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

#define MAX_ARGS 10

int _strncmp(const char *s1, const char *s2, size_t n);
char *_getenv(const char *name);
extern char **environ;
char **parse_input(char *input);
void execute_command(char **args, char *argv0);
void run_command(char **args, char *argv0);
char *get_input();
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
size_t _strlen(const char *str);
char *_strtok(char *s, const char *dlim);

#endif
