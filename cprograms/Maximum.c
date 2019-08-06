


#include<stdio.h>


void readArray(int arr[]){

int i;

for(i=0;i<10;i++)

printf("Enter an integer for element #%d: ",i);

scanf("%d",&arr[i]);

return;

}


int findMax(int a[]){

int max=a[0];

int i;

for(i=1;i<10;i++)

if(max<a[i])

max=a[i];

return max;

}

}

int main(){

int arr[10];

int i;

readArray(arr);

printf("The max integer is :");

printElement(findMax(arr));


return 0;

}

