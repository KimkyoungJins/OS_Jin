`#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

#define N 5

int ccount = 0; // 전역변수 


// 자식이 종료 될 때 마다 이 함수가 호출이 되낟. 
void child_handler(int sig){
    int child_status;
    pid_t pid = wait(&child_status);   // child stats의 주소값을 반환해야하지 pid에 넣을 수 있다. 
    ccount --;      
    printf("Received signal %d from process %d \n", sig, pid);
}        // child 프로세스가 종료 됐을때, 부모가 그 상태값을 받기 위한 함수


int main(){

    pid_t pid[N];
    int i;
    int ccount = N;


    signal(SIGCHLD, child_handler);


    


    return 0;
}