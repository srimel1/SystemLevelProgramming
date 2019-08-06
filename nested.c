#include <stdio.h>
int main()
{
    int number,num2;
    double test;
    printf("Enter an integer: ");
    scanf("%d", &number);
    printf("Enter another integer: ");
    scanf("%d", &num2);

    test = number/num2;
    // True if the remainder is 0
    if  (test == 1) 
    {
        printf("%d is 1.",number);
    }
    else
    {
        printf("%d is an odd integer.",number);
    }
    return 0;
}