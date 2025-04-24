#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define N 5
int ccount;

void child_handler2();


int main(){

    pid_t pid[N];
    int i;
    ccount = N;

    signal(SIGCHLD, child_handler2);
    for(i = 0; i < N; i ++){

        if((pid[i] = fork() == 0)){

            sleep(1);
        }
    }

    return 0;
}