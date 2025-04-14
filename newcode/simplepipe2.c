#include <stdio.h>
#include <unistd.h>
#include <string.h>


// IPC 를 위한 코드이다. 
int main() {

    // 변수를 설정한다. 
    int fd[2];  // 0일때는 읽는 것, 1일때는 쓰는 것이다. 
    char buffer[100];   // 데이터를 읽어올때 저장해야할 공간.
    char msg = "Im your father";    // 쓰게 될 데이터


    pipe(fd);// 파이프를 만든다. 읽고 쓰기 위한. 근데 파이프는 변수로 fd를 받아야 한다. 

    if (fork() == 0) {

        // 자식일 때는 읽는다. 
        read(fd[0], buffer, sizeof(buffer));


    } else{
         // 부모일때는 쓴다. 
         write(fd[1],msg, strlen(msg) + 1);
        
    }

    return 0;
}

