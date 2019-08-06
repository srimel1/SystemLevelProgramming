#include<stdio.h>
void main(){
   int N,i,j;
   printf("Enter size of array: ");
   scanf("%d",&N);
	int arr[&N];
   printf("Enter %d Numbers: \n",N);
   for(i = 0; i < N; i++)
       scanf("%d",&arr[i]);
   for(i = 0; i < N; i++){
       for(j = 0; j < N-i; j++){
           if(arr[j] < arr[j+1]){
               int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
           }
       }
   }
   printf("Sort in descending Order: \n");
   for(i = 0; i < N; i++)
       printf("%d ",arr[i]);
}
