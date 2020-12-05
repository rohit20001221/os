#include<stdio.h>
#include<stdlib.h>

struct Node{
    int seg;
    int base;
    int limit;
    struct Node* next;
};

typedef struct Node Node;

Node *head=NULL;

void insert(int base, int limit, int seg){
    Node *node = (Node *)malloc(sizeof(Node));
    node->base = base;
    node->limit = limit;
    node->seg = seg;
    node->next = NULL;

    if(head = NULL){
        head = node;
    }else{
        node->next = head;
        head = node;
    }
}

int find(int seg){
    Node *ptr = head;
    while(ptr->seg != seg && ptr != NULL){
        ptr = ptr->next;
    }

    if(ptr != NULL)
        return ptr->limit;
    else
        return -1;
}

int search(int seg){
    Node *ptr = head;
    while(ptr->seg != seg && ptr != NULL){
        ptr = ptr->next;
    }

    if(ptr != NULL)
        return ptr->base;
    else
        return -1;
}

int main(){
    int seg, offset, limit, base, c, s, physical;
    printf("Enter segment table\n");

    do{
        printf("Enter segment number (-1 for termination): ");
        scanf("%d", &seg);

        if(seg != -1){
            printf("Enter base address: ");
            scanf("%d", &base);
            printf("Enter value of limit: ");
            scanf("%d", &limit);
            insert(base, limit, seg);
        }

    }while(seg != -1);

    printf("Enter offset: ");
    scanf("%d", &offset);
    printf("Enter segment number: ");
    scanf("%d", &seg);

    c = find(seg);
    s = search(seg);

    if(offset < c){
        physical = s + offset;
        printf("Physical = %d\n", physical);
    }else{
        printf("Physical address not exist\n");
    }

}