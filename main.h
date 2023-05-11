#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void exec(char **argv);

#endif
