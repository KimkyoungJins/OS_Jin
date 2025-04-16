#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(){
    const char * name = "OS";
    const int SIZE = 4096;      // 4키로바이트를 제공하는 것이다. 
    
    int shm_fd;
    void *ptr;
    int i;

    // open the shared memeory segment.
    shm_open(name, O_RDONLY, 0666);

    // shared memeory failed
    if(shm_fd == -1){
        printf("MEMEORY ERROR");
        exit(-1);
    }


    // prtr 사이즈
    ptr = (char*) mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED){
        printf("MAp failed!");
        exit(-1);
    }

    // remove the shared memeory segment
    if(shm_unlink(name) == -1) {
        printf("Error removing %s\n", name);
        exit(-1);
    }

    return 0;

}