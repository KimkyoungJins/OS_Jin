#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

#define READ_NUM 0
#define WRITE_NUM 1
#define BUFFER_SIZE 25

int main() {


    int fd[2];
    pid_t pid;
    const char msg[] = "Hello";
    char buf[32];

    // 1) (파이프 생성)
    if (pipe(fd) < 0) { perror("pipe"); return 1; }

    // 2) (fork)
    pid = fork();
    if (pid < 0) { perror("fork"); return 1; }

    if (pid > 0) {
        // 부모: 쓰기만 사용
        close(fd[READ_NUM]);
        write(fd[WRITE_NUM], msg, strlen(msg)+1);       // write 에서는 strlen이다.
        close(fd[WRITE_NUM]);


    } else {
        // 자식: 읽기만 사용
        close(fd[WRITE_NUM]);
        read(fd[READ_NUM], buf, sizeof(buf));           // read에서는 sizeof이다. 
        printf("Child got: %s\n", buf);
        close(fd[READ_NUM]);
    }

    return 0;
}
