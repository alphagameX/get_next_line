#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

# define MAX_OPEN 65540

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int     get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
void    *ft_memmove(void *dst, const void *src, size_t len);
int		ft_strlen(char *str);
char    *read_line(char *str, char **line); 

#endif