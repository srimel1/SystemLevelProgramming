#include <fcntl.h> /* For file mode definitions */
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#include <string.h>

pthread_t tid[2];

void *doSomething(void *arg) {
//printf("in function");
    int *i= (int *) arg;
    pthread_t id = pthread_self();
    if(pthread_equal(id,tid[0]))
    {
        printf("I am thread 1 my id = %d, and i =  %d\n",id,*i);
    }
    else
	printf("I am thread 2 and my id = %d, and i = %d\n",id,*i);

}

int main()
{
int i;
//printf("asfter struct");

for(i=0; i<2;i++)
{
//printf("before create\n");

	pthread_create(&tid[i], NULL, doSomething, (void *)&i); 
//printf("ch = %d\n",ch);
//sleep(2);
}
//sleep(10);
pthread_join(tid[0], NULL); 
pthread_join(tid[1], NULL); 

return 0;
}
