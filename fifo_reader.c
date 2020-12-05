#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

int main(){
    int choice;
    char *myFifo = "./fifo";
    int fd = open(myFifo, O_RDONLY);
    char buffer[100];

    while(1){
        read(fd, buffer, sizeof(buffer));
        puts(buffer);
    }
}