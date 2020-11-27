#include "get_next_line.h"

int has_return(char *str)
{
    int i;

    i = 0;
    if(!str)
        return (0);
    while(str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char* substr(char *str, int start, int len, int freed)
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
    if(freed == 1) {
        *str = '\0';
        free(str);
    }
    return (new);
}


int get_next_line(int fd, char **line)
{
    int ret;
    int i = 0;
    static char *str;
    char *temp;
    char *t;

    if(fd < 0 || !line || BUFFER_SIZE <= 0 || !(temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (-1);
    
    while (has_return(str) == 0 && (ret = read(fd, temp, BUFFER_SIZE)))
    {   
        if(ret == -1)
            return (-1);
        temp[ret] = '\0';
        str = ft_strjoin(str, temp);
    }
    free(temp);

    if(has_return(str) == 0)
    {
        *line = substr(str, 0, ft_strlen(str), 0);
        *str = '\0';
        free(str);
        return (0);
    }

    while(str[i] != '\n')
        i++;
    
    *line = substr(str, 0, i, 0);
    str = substr(str + (i + 1), 0 , ft_strlen(str) - i, 1);
    return (1);
}

// char *read_line(char *str, char **line)
// {
    // int i;
    // char *tmp;
    // i = 0;

    // while(str[i] != '\n')
    //     i++;
    
    // tmp = str;
    // free(str);
    
//     return (NULL);
// }

