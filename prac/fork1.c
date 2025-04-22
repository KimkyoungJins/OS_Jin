#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

    pid_t pid, my_pid;
    printf("A\n");

    // create new child process
    pid = fork();

    // 음수이면 잘못 생성됨.
    // 0 이상이면 잘 생성된거임.
    if(pid == -1){
        printf("fork failed!!");
        exit(pid);
    }

    // 피드가 0이면 자식 프로세스
    if(pid == 0){
        my_pid = getpid();
        printf("Child process %d has been creagted %d\n", pid, my_pid);

    }
    // 부모 프로세스의 경우
    else {
        my_pid = getpid();
        printf("Parents process %d has been creagted %d\n", pid, my_pid);
    }

    printf("B, %d", my_pid);

    return 0;
}