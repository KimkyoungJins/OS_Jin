#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main() {
    int fd[2];
    pid_t pid;
    char buf[100];

    // 1) 파이프 생성
    if ( pipe(fd) < 0 ) {
        perror("pipe");
        exit(1);
    }

    // 2) 프로세스 분기
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // === 자식 프로세스 ===
        // 읽기 엔드 닫기
        close(fd[READ_END]);

        // 사용자 입력
        printf("Enter a string: ");
        fgets(buf, sizeof(buf), stdin);

        // 파이프에 쓰기
        write(fd[WRITE_END], buf, strlen(buf) + 1);

        // 쓰기 엔드 닫기
        close(fd[WRITE_END]);


    } else {
        // === 부모 프로세스 ===
        // 쓰기 엔드 닫기
        close(fd[WRITE_END]);

        // 파이프에서 읽기
        read(fd[READ_END], buf, sizeof(buf));

        // 문자열을 대문자로 변환
        for (int i = 0; buf[i]; i++) {
            buf[i] = toupper(buf[i]);
        }

        // 결과 출력
        printf("Parent received: %s", buf);

        // 읽기 엔드 닫기
        close(fd[WRITE_END]);
    }

    return 0;
}
