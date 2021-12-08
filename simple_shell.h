#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
/**
 * struct specifier - Structure type defining _printf.
 *
 * @specifier: a character representing the data type.
 * @f: fonction pointer to a functions that prints a data type.
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list ap);
} spe;
extern char **environ;
int _printf(const char *format, ...);
int print_s(va_list ap);
int print_c(va_list ap);
int print_int(va_list ap);
int print_percent(va_list ap);
int convert_binary(va_list ap);
int _strncmp(char *s1, char *s2, int n);
char *find_path(void);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
int _putchar(char c);
char **create_array(char *line, char *delimiter);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int execute(char **av);
char *exist(char *av);
char *_strcat(char *dest, char *src);
char **split_path(char *av, char *delimiter);
char *_strdup(char *str);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_memset(char *s, char b, unsigned int n);
void free_array(char **array);
void handle_err(char *av, char **argv, int loop, char *line);
int is_builtin(char *command);
int builtin_env(void);
int execute_builtin(char **av, char **argv, int loop, char *arg);
int builtin_cd(char *av);
int parseline(int n, char *line);
#endif
