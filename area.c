/* Compute area of a circle */
#include <stdio.h>
#include <math.h>
double pi = 3.1415;

int main()
{
    int rad;
    printf("Enter the radius: ");
    scanf("%d", &rad);

    if(rad > 0)
    {
        double area = pi * pow(rad,2);
        double perimeter = 2 * pi * rad;

        printf("\nArea = %15.2lf\n", area);
        printf("Perimeter = %10.2lf\n", perimeter);
    }
    else
    {
        printf("Negative radius not allowed\n");
    }
    return 0;
    
}