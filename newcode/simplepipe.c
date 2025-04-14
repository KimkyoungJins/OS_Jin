#include <stdio.h>
#include <unistd.h>  // 시스템 한수를 쓰기 위한 헤더이다. 
#include <string.h>     // 문자열 처리함수 strlen()을 사용해야함. 
    

// ipc는 프로세스끼리 서로 정보를 주고 받는 것이다. 
int main(){

    int fd[2];
    char msg[] = "Hey child";
    char bu[100];

    pipe(fd); // 파이프를 생성한다. 


    return 0;
}