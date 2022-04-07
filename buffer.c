#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>

typedef struct Node{
    int fd;
    int lock;
    struct Node* next;
}Node;


Node** buffer_lists;
Node** head_lists;
Node** tail_lists;


void Add_Nodes(int fd, int hash){
    Node* node = (Node*) malloc(sizeof(Node));
    node->fd = fd;
    node->lock = 0;
    head_lists[hash]->next = node;
    head_lists[hash] = head_lists[hash]->next;
    tail_lists[hash] = node;
    tail_lists[hash]->next = buffer_lists[hash]->next;
}

void Buffer_Lists(){
    
    buffer_lists = (Node**)malloc(sizeof(Node)*3);
    head_lists = (Node**)malloc(sizeof(Node)*3);
    tail_lists = (Node**)malloc(sizeof(Node)*3);

    for(int i = 0; i < 3; i++){
        buffer_lists[i] = (Node*)malloc(sizeof(Node));
        head_lists[i] = buffer_lists[i];
        tail_lists[i] = buffer_lists[i];
    }


    // Define 10 file descriptors and hashing them

    for(int i=1; i<=10; i++){
        if(i%3 == 0){
            Add_Nodes(i,0);
        }
        else if (i%3 == 1){
            Add_Nodes(i,1);
        }
        else{
            Add_Nodes(i,2);
        }
    }

}

void Start_Process(int fd, int hash){
    Node* temp = NULL;
    temp = buffer_lists[hash];
    while(fd != temp->fd){
        temp = temp->next;
    }
    while(temp->lock != 0){}
    printf("Readig starting on File Descriptor %d\n", fd);
    temp->lock = 1;
    sleep(5);
    temp->lock = 0;
    printf("Reading finished on File Descriptor %d\n", fd);
}

void* Process(void* args){
    int* fd = (int*)args;
    if(*fd%3 == 0){
        Start_Process(*fd, 0);
    }
    else if(*fd%3 == 1){
        Start_Process(*fd, 1);
    }
    else{
        Start_Process(*fd,2);
    }
    
}

