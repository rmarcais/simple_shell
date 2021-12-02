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
char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
int _putchar(char c);
#endif
