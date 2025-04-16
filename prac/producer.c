#include <fcntl.h>      // shm_open
#include <sys/mman.h>   // mmap
#include <unistd.h>     // ftruncate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *name = "OS";
    const int SIZE = 4096;
    int shm_fd;
    void *ptr;

    // 1) (공유 메모리 열기/생성)
    shm_fd = /* ________________ */;

    // 2) (크기 설정)
    /* ________________ */;

    // 3) (메모리 매핑)
    ptr = /* ________________ */;
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // 4) (문자열 쓰기 예시)
    sprintf(ptr, /* ________________ */);
    // → ptr += strlen(…);

    return 0;
}
