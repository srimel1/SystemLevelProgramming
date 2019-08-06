#include <stdio.h>
int main()
{
    int x, y, *a, *b, temp;
    printf("Enter the value of x and y\n");
    scanf("%d%d", &x, &y);
    printf("Before swap:\nx = %d\ny = %d\n", x, y);

    a = &x;
    b = &y;
    
    temp = *b;
    *b = *a;
    *a = temp;
    
    printf("After swap:\nx = %d\ny = %d\n",x,y);
    return 0;
}
