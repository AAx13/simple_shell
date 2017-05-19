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
void prompt(char **env);

/* _read - function to retreive the string (command) from stdin. */
char *_read(char **env);

/* parse - function that splits the line from stdin. */
char **parse(char *line);

/* exec - function to execute commands from stdin. */
int exec(char **tokens, char *line, char **env);

/* path_cmd - function will search directories in $PATH environment variable */
int path_cmd(char **tokens);

/* build_cmd - builds full command path from command name. */
char *build_cmd(char *token, char *value);

/* built_in - handles built-in programs. */
int built_in(char **tokens, char **env);

/* print_env - prints the current environment to stdout. */
int print_env(char **env);

/* _cd - handles the change directory built-in function. */
int _cd(char **tokens, char **env);

/* _getcwd - gets the current working directory. */
char *_getcwd(char **env);

/* _setenv - updates or adds an environment variable. */
int _setenv(char *name, char *value, char **env);

/* _unsetenv - remove an environment variable. */
int _unsetenv(char *name, char **env);

/* build_var - builds a full environment variable from given name and value. */
char *build_var(char *name, char *value);

/* cd_home - changes directory to home as well as updates environment vars. */
int cd_home(char **env);

/* cd_prev - change to previous directory and update environment variables. */
int cd_prev(char **env);

/* free_env - frees an array of strings containing env variables. */
void free_env(char **env);

/* exit_shell - exits shell with arguments. */
void exit_shell(char **tokens, char *line, char **env);

#endif /* HEADER */
