#include<stdio.h>

#define MAX 50

int main(){
    int page[MAX];
    int num_pages, page_size, num_frames, choice, page_num, offset;

    printf("Enter number of pages: ");
    scanf("%d", &num_pages);
    printf("Enter page size: ");
    scanf("%d", &page_size);
    printf("Enter number of frames: ");
    scanf("%d", &num_frames);
    
    for(int i=0; i < num_pages; i++){
        page[i] = -1;
    }

    printf("Enter page table\n");
    printf("page_number\tframe_number\n-----------\t------------\n");

    for(int i=0; i<num_pages; i++){
        printf("%d\t\t", i);
        scanf("%d", &page[i]);
    }

    choice=1;

    while(choice){
        printf("Enter logical address(page_num, offset): ");
        scanf("%d%d", &page_num, &offset);

        if(page[page_num] == -1){
            printf("Physical address not exist\n");
        }else{
            printf("Physical address: (%d, %d)\n", page[page_num], offset);
        }

        printf("Will you continue(0/1): ");
        scanf("%d", &choice);
    }

}