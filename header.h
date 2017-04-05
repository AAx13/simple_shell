#ifndef HEADER
#define HEADER

/* */
int _putchar(char c);

/* */
int putstr(char *str);

/* */
int str_ncmp(char *str1, char *str2, int n);

/* */
char **parse_line(char *line);

/* */
int exec(char **tokens);

#endif /* HEADER */
