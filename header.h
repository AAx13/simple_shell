#ifndef HEADER
#define HEADER
#include <stdio.h>
extern char **environ;

/* _putchar - writes a character to stdout. */
int _putchar(char c);

/* _atoi - function to turn an ascii representation of a number to int */
int _atoi(char *str);

/* */
void _memset(void *s, int c, size_t n);

/* _strlen - gets the length of a string excluding the null byte. */
size_t _strlen(char *str);

/* */
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

/* */
char *_getpath(void);

/* _read - function to retreive the string (command) from stdin. */
char *_read(void);

/* parse - function that splits the line from stdin. */
char **parse(char *line);

/* exec - function to execute commands from stdin. */
int exec(char **tokens, char *line);

/* path_cmd - function will search directories in $PATH environment variable */
int path_cmd(char **tokens);

/* */
char *b_cmd(char *token, char *value);

/* */
int built_in(char **tokens, char *line);

/* exit_b - exits the program when "exit" command is found. */
void exit_b(char **tokens, char *line);

/* */
void env_b(void);

#endif /* HEADER */
