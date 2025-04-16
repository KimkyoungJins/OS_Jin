#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>

// 다양한 것들 쓰기 위한 헤더들이다. 
// 다양한 것들을 쓰기 위한 헤더들이 많다. 

int main(){
    
    const int SIZE = 4096;  // 공유 메모리의 크기 (4KB)
    const char *name = "OS"; // 공유 메모리의 식별 이름 (문자열)

    const char *message0 = "Studying ";
    const char *message1 = "Operating Systems ";
    const char *message2 = "Is fun!\n";

    int shm_fd;     // 공유 메모리를 열었을 때 얻는 "파일 디스크립터"
    void *ptr;      // mmap()를 통해 매핑된 메모리 주소를 저장할 포인터

    // 1) 이름이 "OS"인 공유 메모리를 생성/열기
    shm_fd = shm_open(
        name,              // "OS"
        O_CREAT | O_RDWR,  // 없으면 생성, 읽기/쓰기 가능
        0666               // 파일 권한(읽기/쓰기 모두 허용)
    );
    if (shm_fd == -1) {
        perror("shm_open");
        return -1;
    }

    // 2) 공유 메모리의 크기를 4KB로 설정
    if (ftruncate(shm_fd, SIZE) == -1) {
        perror("ftruncate");
        return -1;
    }

    // 3) 공유 메모리를 현재 프로세스 주소 공간에 매핑
    ptr = mmap(
        0,                     // 시작 주소: 운영체제가 자동으로 결정
        SIZE,                  // 매핑할 바이트 수 (4KB)
        PROT_READ | PROT_WRITE, // 읽기 / 쓰기 권한
        MAP_SHARED,            // 여러 프로세스와 공유
        shm_fd,                // 어떤 공유메모리 객체(shm_fd)와 연결할지
        0                      // 오프셋 (0이면 처음부터)
    );
    if (ptr == MAP_FAILED) {
        printf("Map failed\n");
        return -1;
    }

    // 4) sprintf를 이용해서 공유 메모리에 문자열을 차례대로 써넣는다.
    sprintf(ptr, "%s", message0);
    ptr += strlen(message0);

    sprintf(ptr, "%s", message1);
    ptr += strlen(message1);

    sprintf(ptr, "%s", message2);
    ptr += strlen(message2);

    return 0;
}
