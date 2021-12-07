<p align = "center">
<img src = https://cdn-website.partechpartners.com/media/images/Holberton_School_Logo.original.png>
</p>

## Background Context
This is a team project for Holberton School. We have to create a Simple shell !

Our team - Rémi and Julien - respectively - :

![Team project Simple Shell](./pictures/team.png)

## Learning Objectives

At the end of this project, we are expected to be able to explain to anyone, without the help of Google:
#### General

    Who designed and implemented the original Unix operating system
    Who wrote the first version of the UNIX shell
    Who invented the B programming language (the direct predecessor to the C programming language)
    Who is Ken Thompson
    How does a shell work
    What is a pid and a ppid
    How to manipulate the environment of the current process
    What is the difference between a function and a system call
    How to create processes
    What are the three prototypes of main
    How does the shell use the PATH to find the programs
    How to execute another program with the execve system call
    How to suspend the execution of a process until one of its children terminates
    What is EOF / “end-of-file”?

## Requirements

#### General

    Allowed editors: vi, vim, emacs
    All of our files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
    All of our files should end with a new line
    A README.md file, at the root of the folder of the project is mandatory
    Our code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
    Our shell should not have any memory leaks
    No more than 5 functions per file
    All of our header files should be include guarded
    We use system calls only when you need to

### List of allowed functions and system calls
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

### Compilation
Our shell will be compiled this way:

```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh```

### Testing
Our shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

### Checking memory leak

To check if our program countains memory leaks, we used the command
```
valgrind <executable>
```
Valgrind dsiplays the prompt and you have to run a command ("ls", "pwd", "ls -l"...):
```
#cisfun$ valgrind ./hsh
==14873== Memcheck, a memory error detector
==14873== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==14873== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==14873== Command: ./hsh
==14873== 
#cisfun$ (Enter command here)
```

When you exit the shell (with Ctrl -d or "exit"), you can see a summary of the memory leaks:
```
#cisfun$ exit
==14970== 
==14970== HEAP SUMMARY:
==14970==     in use at exit: 0 bytes in 0 blocks
==14970==   total heap usage: 20 allocs, 20 frees, 1,781 bytes allocated
==14970== 
==14970== All heap blocks were freed -- no leaks are possible
==14970== 
==14970== Use --track-origins=yes to see where uninitialised values come from
==14970== For lists of detected and suppressed errors, rerun with: -s
==14970== ERROR SUMMARY: 150 errors from 7 contexts (suppressed: 0 from 0)
```
So, here, you can see there is no memory leaks ;-) 

### Table
| Files | Description | Prototype |
|-|-| - |
| [AUTHORS](link)| AUTHORS page |
| [_putchar.c](https://github.com/rmarcais/simple_shell/blob/main/_putchar.c) | puts a character | ```int _putchar(char c)``` |
| [_strcmp.c](https://github.com/rmarcais/simple_shell/blob/main/_strcmp.c) | compares two strings | ```int _strcmp(char *s1, char *s2)``` |
| [_strlen.c](https://github.com/rmarcais/simple_shell/blob/main/_strlen.c) | computes the length of a string | ```int _strlen(char *str)``` |
| [_calloc.c](https://github.com/rmarcais/simple_shell/blob/main/_calloc.c)| allocates memory for an array | ```void *_calloc(unsigned int nmemb, unsigned int size)``` |
| [_getenv.c](https://github.com/rmarcais/simple_shell/blob/main/_getenv.c) | finds an environment variable | ```char *_getenv(const char *name)``` |
| [_printf](https://github.com/rmarcais/simple_shell/blob/main/_printf.c) | reproduction of the fonction printf | ```int _printf(const char *format, ...)``` |
| [_realloc.c](https://github.com/rmarcais/simple_shell/blob/main/_realloc.c) | changes the size of a memory block | ```void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)``` |
| [_strcat.c](https://github.com/rmarcais/simple_shell/blob/main/_strcat.c)| concatenates two strings| ```char *_strcat(char *dest, char *src)``` |
| [_strdup.c](https://github.com/rmarcais/simple_shell/blob/main/_strdup.c) | duplicates a string | ```char *_strdup(char *str)``` |
| [_create_array.c](https://github.com/rmarcais/simple_shell/blob/main/create_array.c) | creates an array containing the user input | ```char **create_array(char *line, char *delimiter)``` |
| [_execute.c](https://github.com/rmarcais/simple_shell/blob/main/execute.c) | executes the command given by the user | ```int execute(char **av)``` |
| [execute_builtin.c](https://github.com/rmarcais/simple_shell/blob/main/execute_builtin.c)| executes a built-in given by the user | ```int execute_builtin(char **av, char **argv, int loop, char *arg)``` |
| [exist.c](https://github.com/rmarcais/simple_shell/blob/main/exist.c) | checks if a command exists in the PATH | ```char *exist(char *av)``` |
| [free_array.c](link) | frees an array | ```void free_array(char **array)``` |
| [functions.c](https://github.com/rmarcais/simple_shell/blob/main/functions.c) | fonctions used by the fonction _printf | ```int (*f)(va_list ap);``` |
| [handle_err.c](https://github.com/rmarcais/simple_shell/blob/main/handle_err.c)| handles errors | ```void handle_err(char *av, char **argv, int loop)``` |
| [is_builtin.c](https://github.com/rmarcais/simple_shell/blob/main/is_builtin.c) | checks if the user input is a built-in | ```int is_builtin(char *command)``` |
| [simple_shell.c](https://github.com/rmarcais/simple_shell/blob/main/simple_shell.c) | main function | ```int main(int argc, char **argv)``` |
| [parseline.c](https://github.com/rmarcais/simple_shell/blob/main/parseline.c) | pase the user input | ```int parseline(int n, char *line)``` |
| [split_path.c](https://github.com/rmarcais/simple_shell/blob/main/split_path.c) | creates an array containing the directories of the PATH | ```char **split_path(char *av, char *delimiter)``` |
| [simple_shell.h](https://github.com/rmarcais/simple_shell/blob/main/simple_shell.h)| header file |
| [man_1_simple_shell](https://github.com/rmarcais/simple_shell/blob/main/man_1_simple_shell)| the manual of our shell |

## Man page
You can open the man page of our shell whith the command 
```
man ./man_1_simple_shell
```

Extract:
![Extract Man Page](https://github.com/rmarcais/simple_shell/blob/main/pictures/man_page.png?raw=true)

## Challenges and group work

### *First part*

Rémi and I started the project by learning the concepts. The first part, has been doing some exercises that we carried on with an other group. This part was about to learn the main functions we were expected to use for the simple_shell program. This part was very intensive, interesting and collaborative.

### *Second part*
After 3 or 4 days of work on the exercises, we started coding both together during 2 or 3 days to develop the main part of the function. After this part together, we split the work in two pieces and so worked alone on our own objectives. 
The main objective was to learn :

- How working with Git and Github to be able to code on our own and be well synchronize with github.

- The memory leaks, was the biggest part of the difficulties we met.

Rémi took the lead on the development part and I took the lead to write the article and the man page.
### *Last part*
After the week end before the deadline, which was on the Wednesday, we did a big overview of our work and continued to improve it.
The experience was great, and the collaboration both together has been quiet fluent and easy.


## Tools

| emacs | google doc |
|:---:|:---:|
| <img width="50" height="50" src=./pictures/logo_emacs.png> | <img width="55" height="55" src=./pictures/logo_google_doc.png> |

## Cloning the repo
To clone thid repository, run the command:
```
git clone git@github.com:rmarcais/simple_shell.git
```

## Authors

| Julien DUFFAY | Rémi Marçais |
|:---:|:---:|
|<a href="https://www.linkedin.com/in/julien-duffay-206822a5/"> <img alt="Julien DUFFAY Linkedin" width="40px" src=./pictures/logo_linkedin.png> <a href="https://github.com/julien3641"> <img alt="Julien DUFFAY Github" width="40px" src=./pictures/logo_github.png> | <a href="https://www.linkedin.com/in/r%C3%A9mi-mar%C3%A7ais-274a4421a/"> <img alt="Rémi Marçais Linkedin" width="40px" src=./pictures/logo_linkedin.png> <a href="https://github.com/rmarcais"> <img alt="Elodie RIOU Github" width="40px" src=./pictures/logo_github.png> |