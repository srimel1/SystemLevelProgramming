#include <stdio.h>

main()
{
    int *p,  x,y P;
     x = 1, y = 2;
    P = *max(&x, &y);
    printf("x = %d y = %d", x,y);
    printf("%d", P);
}
void swap(int *p, int *q)
{
    int temp = 0;
    temp = *p;
    *p = *q;
    *q = temp;
}

int *max(int *a, int *b)
{
    if(*a > *b)
        return a;
    else
    {
        return b;
    }
}
void avgSum(float a[], int n, float *avg, float *sum)
{
    int i;
    sum = 0.0;
    for(i = 0; i < n; i++)
        sum += a[i];
    avg = sum/n;
}
