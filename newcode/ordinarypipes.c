#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>



int main(){


    pid_t pid;
    int fd[2];
    char buffer[100]; // 버퍼에다가 저장을 하기 때문이다. 
    char *message = "Hey hi hello";

    // 파이프 생성하기 
    if (pipe(fd) == -1){

        printf("파이프 생성 실패");
        return 1;
    } 

    // 프로세스를 복제하고
    pid = fork();

    // 0보다 낮으면 실패임
    if (pid < 0){
        perro("fork 실패");
        return 1;

    } else if(pid = 0){  // 자식케이스  읽기전용
        close(fd[1]); // 자식 케이스에서는 읽기만 시킬거임. 따라서 쓰기는 닫아 놓음.
        read(fd[0], buffer, sizeof(buffer));
        printf('%s', buffer);
        close(fd[0]);

    } else{     

        // 부모 프로세스: 쓰기 전용
        close(fd[0]);        // 쓰기 전용이라서 읽기는 닫는다. 
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    }

    return 0;
}