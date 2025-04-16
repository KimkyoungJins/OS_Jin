#include <fcntl.h>      // shm_open
#include <sys/mman.h>   // mmap
#include <unistd.h>     // close
#include <stdio.h>
#include <stdlib.h>


// 컨수머
int main() {
    const char *name = "OS";
    const int SIZE = 4096;
    int shm_fd;
    void *ptr;

    // 1) (공유 메모리 열기)
    shm_fd = shm_open(name, O_RDONLY, 0666);
    if (shm_fd == -1) { perror("shm_open"); exit(1); }

    // 2) (메모리 매핑)
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) { perror("mmap"); exit(1); }

    // 3) (내용 읽어 출력)
    printf("%s\n", (char *)ptr);

    // 4) (공유 메모리 제거)
    if(shm_unlink(name)){
        perror("Ther is an error to eleive ");
        exit:(-1);
    }

    return 0;
}
