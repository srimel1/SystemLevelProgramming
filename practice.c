#include <stdio.h>
#define MAX_SIZE 1000

int main()
{
    int arr[MAX_SIZE];
    int i, N;
    float average = 0, sum = 0;
    /* input size */
    printf("Enter size of array: ");
    scanf("%d", &N);

    /* input elements */
    printf("Enter %d elements in the array: ", N);
    for(i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];

    }

    /* print array */
    printf("\nElements in array are: [");
    for(i=0; i<(N-1); i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("%d]", arr[N-1]);
    
    average = sum/N;
    printf("\nAverage = %0.2f\n", average);
    return 0;
}