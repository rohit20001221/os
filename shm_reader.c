#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdlib.h>

#define SHM_SIZE 1024

int main(){
    key_t key = ftok("shm.txt", 15);
    int shmid = shmget(key, SHM_SIZE, 006 | IPC_CREAT);
    char *data = shmat(shmid, NULL, 0);
    printf("%s\n", data);
    shmdt(data);

}