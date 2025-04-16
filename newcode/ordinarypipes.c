#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>



int main(){


    pid_t pid;
    int fd[2];
    char buffer[100]; // 버퍼에다가 저장을 하기 때문이다. 

    // 프로세스를 복제하고
    pid = fork();


    if(pipe(fd)){


    }



    return 0;
}