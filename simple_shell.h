#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
extern char **environ;
char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
int _putchar(char c);
char **create_array(char *line, char *delimiter);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int execute(char **av);
char *exist(char *av);
char *_strcat(char *dest, char *src);
#endif
