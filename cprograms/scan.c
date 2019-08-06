#include <stdio.h>

void main()
{
   int i,n,a[100];
   
       printf("\n\nAccept N integers from use, and display them to the screen :\n");
       printf("------------------------------------------------------------------------\n");
   
   printf("Input the number of elements you wish to be in your array :");
   scanf("%d",&n);
   
   printf("Input %d number of elements to store in your array :\n",n);
   for(i=0;i<n;i++)
      {
	  printf("element %d : ",i);
	  scanf("%d",&a[i]);
	  }
      
   printf("\nThe values stored into the array are : \n");
   for(i=0;i<n;i++)
     {
	   printf("% 5d",a[i]);
	 }
 
   printf("\n\nThe values stored into the array in reverse are :\n");
   for(i=n-1;i>=0;i--)
      {
	   printf("% 5d",a[i]);
	  }
   printf("\n\n");
} 

