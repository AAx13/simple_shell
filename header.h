#ifndef HEADER
#define HEADER
#include <stdio.h>

/* */
int _putchar(char c);

/* */
int _atoi(char *str);

/* */
size_t _strlen(char *str);

/* */
char *_strcpy(char *dest, char *src);

/* */
char *_strcat(char *dest, char *src);

/* */
int _strcmp(const char *s1, const char *s2);

/* */
int putstr(char *str);

/* */
char *_read(void);

/* */
char **parse(char *line);

/* */
int exec(char **tokens, char *line);

/* */
int path_cmd(char **tokens);

#endif /* HEADER */
