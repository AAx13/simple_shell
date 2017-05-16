# Simple Shell Project

## Usage

Run `make` and then `./simple_shell` or `make run` in console.

`man simple_shell`

`exit` or `Ctrl + D` to exit shell.

## Other Make Commands
* `make gdb` - Compile for gdb debugging.
* `make run-v` - Run with valgrind -v (verbose).
* `make run-m` - Run with valgrind for memory leak checks.
* `make run-e` - Run with valgrind for error checks.
* `make clean` - Clean up binary, unnecessary files, and man page.

## Functions
[putchar.c](../master/putchar.c)
```c
/* _putchar - writes a character to stdout. */
int _putchar(char c);
```

[atoi.c](../master/atoi.c)
```c
/* _atoi - function to turn an ascii representation of a number to int */
int _atoi(char *str);
```

[memset.c](../master/memset.c)
```c
/* _memset - fills memory with a constant byte */
void _memset(void *s, int c, size_t n);
```

[strlen.c](../master/strlen.c)
```c
/* _strlen - gets the length of a string excluding the null byte. */
size_t _strlen(char *str);
```

[strdup.c](../master/strdup.c)
```c
/* _strdup - duplicate a string. */
char *_strdup(char *str);
```

[strcpy.c](../master/strcpy.c)
```c
/* _strcpy - copies the string (src) to the string (dest). */
char *_strcpy(char *dest, char *src);
```

[strcat.c](../master/strcat.c)
```c
/* _strcat - concatenates two strings. */
char *_strcat(char *dest, char *src);
```

[strcmp.c](../master/strcmp.c)
```c
/* _strcmp - compares two strings. */
int _strcmp(const char *s1, const char *s2);
```

[strncmp.c](../master/strncmp.c)
```c
/* _strncmp - compares (n) amount of characters of two strings. */
int _strncmp(const char *s1, const char *s2, size_t n);
```

[putstr.c](../master/putstr.c)
```c
/* putstr - writes a string to stdout. */
int putstr(char *str);
```

[getenv.c](../master/getenv.c)
```c
/* _getenv - Gets the value of an environment variable. */
char *_getenv(char *var);
```

[prompt.c](../master/prompt.c)
```c
/* prompt - prints the shell prompt */
void prompt(void);
```

[read.c](../master/read.c)
```c
/* _read - function to retreive the string (command) from stdin. */
char *_read(void);
```

[parse.c](../master/parse.c)
```c
/* parse - function that splits the line from stdin. */
char **parse(char *line);
```

[exec.c](../master/exec.c)
```c
/* exec - function to execute commands from stdin. */
int exec(char **tokens, char *line);
```

[path_cmd.c](../master/path_cmd.c)
```c
/* path_cmd - function will search directories in $PATH environment variable */
int path_cmd(char **tokens);
```

[build_cmd.c](../master/build_cmd.c)
```c
/* b_cmd - builds full command path from command name. */
char *b_cmd(char *token, char *value);
```

[built_in.c](../master/built_in.c)
```c
/* built_in - handles built-in programs. */
int built_in(char **tokens, char *line);
```

[env.c](../master/env.c)
```c
/* env_b - prints the current environment to stdout. */
int env_b(void);
```

[cd.c](../master/cd.c)
```c
/* _cd - handles the change directory built-in function. */
int _cd(char **tokens);
```

[getcwd.c](../master/getcwd.c)
```c
/* _getcwd - gets the current working directory. */
char *_getcwd(void);
```