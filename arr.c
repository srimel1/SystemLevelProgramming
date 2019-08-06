#include <stdio.h>
#define MAX 100

int main()
{
    int N, i;
    int arr[MAX];
    
    printf("Enter the number of elements: ");
    scanf("%d", &N);
    
    arr[N];
    printf("Enter the elements: \n");
    for(i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }

    printf("Your elements are...\n");
    for(i = 0; i < N; i++){
        printf("%d", arr[i]);
        printf("\n");
    }
}