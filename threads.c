#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

/* global variables */
pthread_t tid[2];


void *doSomething(void *arg)
{
    int *i = (int *) arg;
    pthread_t id = pthread_self();
    if(pthread_equal(id, tid[0]))
    {
        printf("I am thread 1. My id = %d and i = %d\n", id, *i);
    }else
    {
        printf("I am thread 2. My id = %d and i = %d\n", id, *i);
    }
    
}
int main()
{
    int i = 0;
    while(i < 2)
    {
        pthread_create(&tid[i], NULL, doSomething, (void *)&i);
        sleep(1);
        i++;
    }
    sleep(5);
    return 0;
}