#include "get_next_line_bonus.h"

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

    if(!(new = malloc(sizeof(char) * (len + 1))))
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
    static char *str[MAX_OPEN];
    char *temp;

    if(fd < 0 || BUFFER_SIZE <= 0 || !(temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (-1);
    
    while (has_return(str[fd]) == 0)
    {
        ret = read(fd, temp, BUFFER_SIZE); 
        if (ret == 0)
        {
            *line = substr(str[fd], 0, ft_strlen(str[fd]));
            free(temp);
            return (0);
        }
        if(ret == -1)
            return (-1);
        temp[ret] = '\0';
        str[fd] = ft_strjoin(str[fd], temp);
    }

    str[fd] = read_line(str[fd], line);
    free(temp);
    return (1);
}

char *read_line(char *str, char **line)
{
    int i;
    char *tmp;
    i = 0;


    while(str[i])
    {
        if(str[i] == '\n')
        {
            *line = substr(str, 0, i);
            tmp = str;
            free(str);
            str = substr(tmp + (i + 1), 0 , ft_strlen(tmp) - i);
            return (str);
        }
        i++;
    }
    return (NULL);
}

