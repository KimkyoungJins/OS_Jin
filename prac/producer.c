#include <fcntl.h>      // shm_open
#include <sys/mman.h>   // mmap
#include <unistd.h>     // ftruncate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *name = "OS";
    const char *message0 ="Studying \n";
    const char *message1 ="Operationg Systme \n";
    const char *message2 ="is fun!!! \n";

    const int SIZE = 4096;
    int shm_fd;
    void *ptr;

    // 1) (공유 메모리 열기/생성)
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    // 2) (크기 설정)
    // 해당 메모리 객체의 크기를 정해준다. 
    // 4키로 바이트로 간다. 
    ftruncate(shm_fd, SIZE);

    // 3) (메모리 매핑)
    ptr = mmap(0, PROT_READ, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // 4) (문자열 쓰기 예시)
    sprintf(ptr, "%s", message0);
    ptr = ptr + strlen(message0);

    sprintf(ptr, "%s", message1);
    ptr = ptr + strlen(message1);

    sprintf(ptr, "%s", message2);
    ptr = ptr + strlen(message2);

    return 0;
}
