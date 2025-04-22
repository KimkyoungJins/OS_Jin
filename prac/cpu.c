#include <stdio.h>
#include <stdlib.h>
#include "common.h"



int main(int argc, char *argv[]){

    if(argc != 2){
        fprintf(stderr,"This is the big error\n");
        exit(1);
    }

    char *str = argv[1];

    while(1){
        printf("%s", str);
        Spin(1);
    }


    return 0;
}