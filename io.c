#include<fcntl.h>
#include<unistd.h>
#include<string.h>
// #include<stdio.h>

int main(){
    int fd = 1;
    char buffer[] = "Hello World\n";
    char buffer2[100];

    int fd_in = open("input2.txt", O_CREAT | O_RDWR | O_EXCL);
    write(fd_in, buffer, strlen(buffer));

    read(fd_in, &buffer2, strlen(buffer));
    close(fd_in);

    // printf("%s\n", buffer2);

    write(fd, buffer2, 3);
    close(fd);
   
    return 0;
}