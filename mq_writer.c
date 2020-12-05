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
    message.message_type = 1;
    // message.message_text = "Hello World!!";
    printf("Enter Data: ");
    fgets(message.message_text, 100, stdin);

    msgsnd(msgid, &message, sizeof(message), 0);
    return 0;
}