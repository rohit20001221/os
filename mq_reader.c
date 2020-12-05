#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct message_buffer{
    int message_type;
    char message_text[100];
} message;

int main(){
    key_t key = ftok("mq.txt", 15);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    msgrcv(msgid, &message, sizeof(message), 1, 0);
    printf("%s\n", message.message_text);

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}