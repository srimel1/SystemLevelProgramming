



#include <stdio.h>

int main(){
   double arr[6];
   int i;
   double sum, avg, max, min;
   printf("Enter 6 numbers: \n");
   for(i = 0;i<6;i++){
       scanf("%lf",&arr[i]);
   }
   max = arr[0];
   min = arr[0];
   sum = arr[0];
   for(i = 1;i<6;i++){
       if(max < arr[i]){
           max = arr[i];
       }
       if(min > arr[i]){
           min = arr[i];
       }
       sum += arr[i];
   }
   avg = sum /6;
   printf("\nMinimum: %.2lf\n",min);
   printf("Maximum: %.2lf\n",max);
   printf("Average: %.2lf\n",avg);
  
  
   return 0;
}
