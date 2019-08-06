

#include <stdio.h>

#define MAX_SIZE 100 // Maximum array size

int main() { 

int arr[MAX_SIZE];

int i, max, min, size,sum=0,avg=0;

/* Input size of the array */

printf("Enter size of the array: ");

scanf("%d", &size);

/* Input array elements */

printf("Enter elements in the array: ");

for(i=0; i<size; i++) {

scanf("%d", &arr[i]);

}

/* Assume first element as maximum and minimum */

max = arr[0];

min = arr[0];

/* * Find maximum and minimum in all array elements. */

for(i=1; i<size; i++) {

/* If current element is greater than max */

if(arr[i] > max) {

max = arr[i];

}

/* If current element is smaller than min */

if(arr[i] < min) {

min = arr[i];

}

/* calculating sum*/

sum=arr[i]+sum;

}

/* Calculating Average*/

avg=sum/size;

/* Print maximum, minimum,sum and average element */

printf("Maximum element = %d\n", max);

printf("Minimum element = %d", min);

printf("Sum element = %d", sum);

printf("Average element = %d", avg);

return 0;

}

