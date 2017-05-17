#ifndef HEADER
#define HEADER
#include <stdio.h>
extern char **environ;

/* _putchar - writes a character to stdout. */
int _putchar(char c);

/* _atoi - function to turn an ascii representation of a number to int */
int _atoi(char *str);

/* memset - fills memory with a constant byte */
void _memset(void *s, int c, size_t n);

/* _strlen - gets the length of a string excluding the null byte. */
size_t _strlen(char *str);

/* _strdup - duplicate a string. */
char *_strdup(char *str);

/* _strcpy - copies the string (src) to the string (dest). */
char *_strcpy(char *dest, char *src);

/* _strcat - concatenates two strings. */
char *_strcat(char *dest, char *src);

/* _strcmp - compares two strings. */
int _strcmp(const char *s1, const char *s2);

/* _strncmp - compares (n) amount of characters of two strings. */
int _strncmp(const char *s1, const char *s2, size_t n);

/* putstr - writes a string to stdout. */
int putstr(char *str);

/* _getenv - Gets the value of an environment variable. */
char *_getenv(char *name);

/* prompt - prints the shell prompt */
void prompt(void);

/* _read - function to retreive the string (command) from stdin. */
char *_read(void);

/* parse - function that splits the line from stdin. */
char **parse(char *line);

/* exec - function to execute commands from stdin. */
int exec(char **tokens, char *line);

/* path_cmd - function will search directories in $PATH environment variable */
int path_cmd(char **tokens);

/* build_cmd - builds full command path from command name. */
char *build_cmd(char *token, char *value);

/* built_in - handles built-in programs. */
int built_in(char **tokens);

/* env_b - prints the current environment to stdout. */
int env_b(void);

/* _cd - handles the change directory built-in function. */
int _cd(char **tokens);

/* _getcwd - gets the current working directory. */
char *_getcwd(void);

/* */
int _setenv(char *name, char *value);

/* */
char *build_env(char *name, char *value);

#endif /* HEADER */
