#include <stdio.h>
#include <unistd.h>


int main(){

    pid_t pid;
    pid = fork();

    if(pid == 0){
        printf("child1 %d, %d", getpid(), getpgrp());

    } else {
        printf("Parent pid = %d, %d", getpid(), getpgrp());
    }

    while(1)

    return 0;
}