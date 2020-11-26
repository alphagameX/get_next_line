#include "get_next_line.h"

int has_return(char *str)
{
    int i;

    i = 0;
    if(!str)
        return (0);
    while(str[i])
    {
        if (str[i] == '\n' || str[i] == '\0')
            return (1);
        i++;
    }
    return (0);
}

char* substr(char *str, int start, int len)
{
    char *new;

    if(!(new = malloc(sizeof(char) * len + 1)))
        return (NULL);
    while(str[start] && start < len)
    {
        new[start] = str[start];
        start++;
    }
    new[start] = '\0';
    return (new);
}


int get_next_line(int fd, char **line) {
    int ret;
    static char *str;
    char *temp;

    if(fd < 0 || BUFFER_SIZE <= 0 || !(temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (-1);
    
    while (has_return(str) == 0)
    {
        ret = read(fd, temp, BUFFER_SIZE); 
        if (ret == 0)
        {
            *line = substr(str, 0, ft_strlen(str));
            return (0);
        }
        if(ret == -1)
            return (-1);
        temp[ret] = '\0';
        str = ft_strjoin(str, temp);
    }

    str = read_line(str, line);
    free(temp);
    return (1);
}

char *read_line(char *str, char **line)
{
    int i;
    i = 0;


    while(str[i])
    {
        if(str[i] == '\n')
        {
            *line = substr(str, 0, i);
            str = substr(str + (i + 1), 0 , ft_strlen(str) - i);
            return (str);
        }
        i++;
    }
    return (NULL);
}

