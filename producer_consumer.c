#include<stdio.h>
#include<stdlib.h>

int wait(int s){
    return (--s);
}

int signal(int s){
    return (++s);
}

int mutex = 1, full = 0, empty = 3, count = 0;

void producer(){
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
        count++;
        printf("Producer produces item %d\n", count);
    mutex = signal(mutex);
}

void consumer(){
    mutex = wait(mutex);
    empty = signal(empty);
    full = wait(full);
        printf("Consumer consumes item %d\n", count);
        count--;
    mutex = signal(mutex);
}

int main(){
    int choice;

    while(1){
        printf("1.Produce\n2.Consume\n3.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(mutex == 1 && empty != 0)
                    producer();
                else
                    printf("Buffer full\n");

                break;
            case 2:
                if(mutex == 1 && full != 0)
                    consumer();
                else
                    printf("Buffer is empty\n");
                
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
