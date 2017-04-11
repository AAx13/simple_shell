#ifndef HEADER
#define HEADER
#include <stdio.h>

/* */
int _putchar(char c);

/* */
size_t _strlen(char *str);

/* */
char *_strcat(char *dest, char *src);

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
