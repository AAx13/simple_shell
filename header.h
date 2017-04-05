#ifndef HEADER
#define HEADER

/* */
int _putchar(char c);

/* */
int putstr(char *str);

/* */
int sncmp(char *str1, char *str2, int n);

/* */
char **parse(char *line);

/* */
int exec(char **tokens, char *line);

#endif /* HEADER */
