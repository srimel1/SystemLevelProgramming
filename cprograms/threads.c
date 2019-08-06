#include<stdio.h>

#include<string.h>

#include<pthread.h>

#include<stdlib.h>

#include<unistd.h>

pthread_t tid[2];

void *doSomething(void *arg)
{
pthread_t thread_id;
thread_id=pthread_self();
if(thread_id == tid[0])
{
printf("I am thread1 and value of i is : %d\n",(int*)arg);
}
if(thread_id == tid[1])
{
printf("I am thread2 and value of i is : %d\n",(int*)arg);
}
}

int main()

{

int i =0;

while (i<2)

{

//create thread here. Example given below ( not 100% correct )
//pthread_create(tid[i],NULL,&doSomething,(Fill last argument yourself)); // have to pass i in the last argument, but how ? google is your friend.
pthread_create(&tid[i],NULL,&doSomething,(void*)i);
++i;

} sleep(5); // waiting for the threads to finish.
i = 0;
while(i < 2)
{
pthread_join(tid[i],NULL);
++i;
}

return 0;

}
