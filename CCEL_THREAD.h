#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX_THREAD 8;


typedef void*(*general_function_type)(void*);
typedef void* general_function_args;

struct Thread{
    pthread_t* thread;
    const pthread_attr_t* attr;
    general_function_type function;
    general_function_args args;
};

struct Threads{
    unsigned int size;
    //一个柔性数组
    Thread* threads[];
};

struct Thread_pool{

    int current_status[];
    pthread_t current_ids[];
    Thread* threads;
    unsigned int size;
};
/*
    -1,not using;
    1,running;
*/
Thread* Thread_new(pthread_t* thread,
    const pthread_attr_t* attr,
    general_function_type function,
    general_function_args args){
        Thread* t;
        t->thread = (pthread_t*)malloc(sizeof(pthread_t*));
        t->thread = thread;

        t->attr = (pthread_attr_t*)malloc(sizeof(pthread_attr_t*));
        t->attr = attr;

        t->function = (general_function_type)malloc(sizeof(general_function_type));
        t->function = function;
        
        t->args = (general_function_args)malloc(sizeof(general_function_args));
        t->args = args;
        return t;
    }

void* queue(Thread_pool *p,Threads* _ts){

}