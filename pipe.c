#include<stdio.h>
#include<stdlib.h>
#include <ctype.h> 
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

int main(){
    int fd[2];
    char s[100];
    int p;

    if(pipe(fd) == -1){
        perror("Pipe failed:");
    }

    printf("Send data: ");
    scanf("%s", s);
    p = fork();

    if(p < 0){
        perror("Fork failed:");
        exit(0);
    }else if(p > 0){
        char output[100];
        close(fd[0]);

        write(fd[1], s, strlen(s));
        close(fd[1]);

        wait(NULL);
    }else{
        close(fd[1]);
        char output[200];
        read(fd[0], output, 100);
        for(int i=0; i<strlen(output); i++){
            output[i] = toupper(output[i]);
        }

        printf("From parent: %s\n", output);
        close(fd[0]);
        exit(0);
    }
}