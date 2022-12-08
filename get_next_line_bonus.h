#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
# endif

char *get_next_line(int fd);
char *get_next(char *arr);
char *get_line(char *arr);
char *read_arr(int fd, char *arr);
char *ft_strchr(char *s, int c);
char *ft_strjoin(char *left_str, char *buff);
size_t ft_strlen(char *s);

#endif
