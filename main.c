#include <fcntl.h>

#include "get_next_line.h"

int main(int argc, char **argv) {
   
    int fd; 
    char *line;

    fd = open("file", O_RDONLY);
 
    while(get_next_line(fd, &line) == 1) {
        printf("%s\n", line); 
        free(line);
    }

    printf("%s\n", line);
    free(line);

    system("leaks a.out");
    return (0);
}

