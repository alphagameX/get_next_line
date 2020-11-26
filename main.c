#include <fcntl.h>

#include "get_next_line.h"

int main(int argc, char **argv) {
   
    int fd; 
    char **line;

    fd = open("file", O_RDONLY);
 
    while(get_next_line(fd, line) == 1) {
        printf("%s\n", *line); 
    }

    printf("%s\n", *line);

    return (0);
}

