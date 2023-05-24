#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;
char **tokenize_input(char *input, const char *delim);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
pid_t exec(char **argv);
char *_getpath(char *pcommand);
int _strcmp(char *s1, char *s2);
char *get_path(char *pcommand);
char *_strdup(char *str);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif
