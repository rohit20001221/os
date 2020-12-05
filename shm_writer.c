#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/ipc.h>

#define SHM_SIZE 1024

int main(){
    key_t key = ftok("shm.txt", 15);
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    char *data;
    data = shmat(shmid, NULL, 0);
    printf("Enter data: ");
    fgets(data, 100, stdin);
    shmdt(data);

    return 0;
}