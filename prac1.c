



#include <stdio.h>

void main()
{
int array[10];
int i, N;




printf("Enter the value of N\n");
scanf("%d",&N);

printf("Enter the elements one by one\n");
for(i=0; i<N ; i++)
{
scanf("%d",&array[i]);
}
printf("Input array is\n");
for(i=0; i<N ; i++)
{
printf("%d\n",array[i]);
}

}
