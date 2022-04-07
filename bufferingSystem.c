#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include "buffer.h"


int main(){

    Buffer_Lists();

    pthread_t thread1, thread2, thread3;
    
    for(int i=1; i<50; i++){
        int file = i%11;
        if(i%3 == 0){
            pthread_create(&thread1, NULL, Process, (void*)&file);
        }
        else if(i%3 == 1){
            pthread_create(&thread2, NULL, Process, (void*)&file);
        }
        else{
            pthread_create(&thread3, NULL, Process, (void*)&file);
        }
    }
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

}