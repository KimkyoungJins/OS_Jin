#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define N 5

int ccount = 0; // 전역변수: 리핑 되지 않은 자식의 수이다. 


// 자식이 종료 될 때 마다 이 함수가 호출이 된다. 
// 사용자가 알아서 만드는 sighandler이다. 
void child_handler(int sig){
    int child_status;
    pid_t pid = wait(&child_status);   // child stats의 주소값을 반환해야하지 pid에 넣을 수 있다. 
    ccount --;      
    printf("Received signal %d from process %d \n", sig, pid);
}        // child 프로세스가 종료 됐을때, 부모가 그 상태값을 받기 위한 함수


void main(){

    pid_t pid[N];
    int i;
    int ccount = N;

    // 자식이 중료될 때마다 호출되는 함수이다. 
    // 자식이 종료될때 커널에서 그냥 부모 프로세스에게 보낸다. 굳이 반복해서 보낼 필요는 없다. 

    signal(SIGCHLD, child_handler);

    for(i = 0; i < N; i++){
        if((pid[N] = fork()) == 0){
            exit(0);
        }
    }

    // 모든 자식이 리핑될 때까지 대기한다. 
    while(ccount > 0){
        pause();        // 시그널이 오기 전까지 현재 프로세스를 중단 시킨다. 
    }

    return 0;
}