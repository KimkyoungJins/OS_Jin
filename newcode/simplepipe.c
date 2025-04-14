#include <stdio.h>
#include <unistd.h>  // 시스템 한수를 쓰기 위한 헤더이다. 
#include <string.h>     // 문자열 처리함수 strlen()을 사용해야함. 
    

// ipc는 프로세스끼리 서로 정보를 주고 받는 것이다. 
int main(){

    //  fork()로 부모와 자식 프로세스를 만들고,
    // pipe()로 만든 통로를 이용해서 부모가 데이터를 쓰고 자식이 읽는 구조야!

    int fd[2];      // 파이프를 사용할때 시스템이 만들어주는 파일 배열
                    // 0읽는다. 1 쓴다. 한쪽은 쓰고 한쪽은 읽는 식이다. 
    char msg[] = "Hey child";
    char buf[100];  // 자식이 데이터를 받을 버퍼이다. 


    pipe(fd); // 파이프를 생성한다. 
                // 이 함수는 fd0, fd1에 읽기 쓰기 전용 파일 디스크립터를 만들어준다.
                // 성공하면 0, 실패하면 -1을 리턴한다. 

    if(fork() == 0){
        read(fd[0], buf, sizeof(buf));  // 읽기
        printf("자식이 받은 메시지는 %s\n", buf);
    } else {
        // 부모 프로세스일 경우
        write(fd[1], msg, strlen(msg) + 1);
    }

    return 0;
}