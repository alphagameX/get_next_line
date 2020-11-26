#include <fcntl.h>

#include "get_next_line.h"

int main(int argc, char **argv) {
   
    int fd; 
    char **line;

    line = (char **)malloc(sizeof(char *) * 1);

    fd = open("file", O_RDONLY);
 
    get_next_line(fd, line);
    printf("%s\n", *line);

    free(line);

    return (0);
}

