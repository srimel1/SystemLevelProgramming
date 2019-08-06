/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <fcntl.h> /* For file mode definitions */
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#include <string.h>

pthread_t tid[2];
struct ft 
{
    char *file_name;
    int start_index;
    int end_index;
    int totalCount;
};

void *threadCount(void *arg) {
//printf("in function");
    int i;
    pthread_t id = pthread_self();

    printf("id = %d, and thread1 id is %d\n",id,tid[0]);
    char c;
	int count=0;
    struct ft* fi = (struct ft*)arg;
	FILE *file;
     file = (FILE*) fopen(fi->file_name,"r");
  //  printf("fileopened");
    fseek (file , fi->start_index, SEEK_SET);
    for(i = 0; i < fi->end_index - fi->start_index; i++)
    {
        c = getc(file);
        if(c=='i')
			count++;
			
    }

		fi->totalCount=count;

}

int main()
{
struct ft f[2];

//printf("asfter struct");

f[0].file_name = (char *) malloc(20);
f[0].file_name="input.txt";
f[0].start_index=0;
f[0].end_index=30;
f[0].totalCount=0;

f[1].file_name= (char *) malloc(20);
f[1].file_name="input.txt";
f[1].start_index=31;
f[1].end_index=75;
f[1].totalCount=0;
//printf("afterassigning");
int i;
/*struct ft ff;
ff.file_name= (char *) malloc(20);
ff.file_name="input.txt";
ff.start_index=0;
ff.end_index=10;
ff.totalCount=0;
*/
//pthread_t tid[2];
//pthread_t tt;
for(i=0; i<2;i++)
{
//printf("before create\n");

pthread_create(&tid[i], NULL, threadCount, (void *)&f[i]); 
//printf("ch = %d\n",ch);
}
//sleep(10);
pthread_join(tid[0], NULL); 
pthread_join(tid[1], NULL); 

int count = f[0].totalCount + f[1].totalCount;

printf("total Count = %d\n",count);
return 0;
}
