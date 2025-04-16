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
    
    
    const int SIZE = 4096;  // 공유 메모리의 크기이다. 
    const char *name = 'OS';
    const char *message1 = "Operating Systems";
    const char *message2 = "Is fun!\n";

    int shm_fd; // 내부적으로 이름을 이용해 공유 메모리를 식별한다. 
    void *ptr;     // mmap() 호출후 반환된 매핑된 메모리 주소를 저장할 포인터이다. 


    // create the shared memeory segment
    // shared memory segment를 만든다. 
    // 공유 메모리를 여는 방법이다. 
    shm_fd = 
    shm_open(name,          // OS라는 이름
        O_CREAT | O_RDWR,   // 없으면 생성, 읽기/쓰기 가능하다. 
        0666);              // 파일권한(읽기/쓰기 모두 가능하다)


    shm_open(name, O_CREAT | O_RDWR, 0666);

    ftruncateI(shm_fd,SIZE);

    // now map the shared memeory segment



}