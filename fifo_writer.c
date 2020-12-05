#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
    int fd;
    char *myFifo = "./fifo";

    mkfifo(myFifo, 0666);
    char buffer[100];

    while(1){
        fd = open(myFifo, O_WRONLY);
        fgets(buffer, 100, stdin);
        write(fd, buffer, sizeof(buffer));
        close(fd);
    }
}