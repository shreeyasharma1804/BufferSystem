#include<iostream>
#include<stdlib.h>
#include<sys/mman.h>
#include<string.h>

using namespace std;

void* memcpyI(void* dest, void* src, size_t len){

    char* d = (char*)dest;
    char* s = (char*)src;

    while(len){
        *d++ = *s++;
        len--;
    }

    return dest;

}

void* memmoveI(void* dest, void* src, size_t len){
    char* d = (char* )dest;
    char* s = (char*)src;

    if(d < s){
        while(len){
            *d++ = *s++;
            len--;
        }
    }
    else{
        char* ld = d+len-1;
        char* ls = s+len-1;
        while(len){
            *ld-- = *ls--;
            len--;
        }
    }
}
