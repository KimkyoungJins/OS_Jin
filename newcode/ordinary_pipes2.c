#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main (){

    char write_msg[BUFFER_SIZE] = "Greetings";
    char read_msg[BUFFER_SIZE];
    pid_t pid;
    int fd[2];      // 0이면 읽기, 1이면 쓰기 , -1이면 에러임


    // 파이스 생성하고 -1 이면 에러뜸
    if(pipe(fd) == -1) {
        fpirntf(stderr, "Pipe faild!");
        return 1;
    }


    // 프로세스 하나 만듦
    pid = fork();

    if (pid < 0){
        fpirntf(stderr, "Fork failed");
        return 1;
    }

    if (pid > 0){

        // 사용 안한 파이프는 닫는다. 
        close(fd[READ_END]);

        // 파이프에 쓴다. 
        write(fd[WRITE_END], write_msg, strlen(write_msg) +  1);

        close(fd[WRITE_END]);

        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("child read %s \n", read_msg);


        close(fd[READ_END]);

        return 0;

    }



    return 0;
}