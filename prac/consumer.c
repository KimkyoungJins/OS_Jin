#include <fcntl.h>      // shm_open
#include <sys/mman.h>   // mmap
#include <unistd.h>     // close
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *name = "OS";
    const int SIZE = 4096;
    int shm_fd;
    void *ptr;

    // 1) (공유 메모리 열기)
    shm_fd = /* ________________ */;
    if (shm_fd == -1) { perror("shm_open"); exit(1); }

    // 2) (메모리 매핑)
    ptr = /* ________________ */;
    if (ptr == MAP_FAILED) { perror("mmap"); exit(1); }

    // 3) (내용 읽어 출력)
    printf("%s\n", /* ________________ */);

    // 4) (공유 메모리 제거)
    /* ________________ */;

    return 0;
}
