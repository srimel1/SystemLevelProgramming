#include<stdio.h>

int main()
{
   int n, number = 1, i, count = 0;
  
   printf("Enter the value of n: ");
   scanf("%d", &n);
  
   printf("First %d prime numbers are: ", n);
  
   while(1)
   {
       int p = 0;
      
       for(i = 1; i <= number; i++)
       {
           if(number % i == 0)
               p++;
       }
       if(p != 2)
       {
           printf("%d ", number);
          
           count++;
       }
       if(count == n)
           break;
       number++;
   }
}
