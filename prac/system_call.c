#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define FILELEN 256
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int fd;
    int start_offset;
    int read_bytes;
    char filename[FILELEN];
    char buf[BUFSIZE];

    if(argc < 3){
        fprintf(stderr, "Usage: %s [file name] [start offset]\n", argv[0]);
        exit(1);
    }

    lseek(fd, start_offset, SEEK_SET);

    while((read_bytes = read(fd, buf, BUFSIZE)) > 0) {

        write(1, buf, read_bytes);

    }

    printf("/n/n");

    close(fd);

    return 0;
}