#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
void * doSomething(void*arg)
{
	int *i = (int *) arg;
	pthread_t id = pthread_self();
	if(pthread_equal(id,tid[0]))
		printf("this is thread 1, i = %d\n",*i);
	else
		printf("this is thread 2, i = %d\n",*i);
 
}



int main()
{
int i=0;

while(i<2)
{
	pthread_create(&tid[i],NULL,doSomething,(void *)&i);
	sleep(1);
	i++;
}
sleep(2);

return 0;
}
