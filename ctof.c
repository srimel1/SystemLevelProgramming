#include <stdio.h>

int main()

{
    int farh = 0, cel = 0, lower = 0, upper = 0, step = 0;
    lower = 0;
    upper = 300;
    step = 20;
    farh = lower;
    int c;
    printf("Enter the farenheit temperature you wish to convert to celcius: ");
    scanf("%d", &c);
    int temp;
    temp = convert(c);
    printf("Celcius temperature is: %d\n", temp);
    while(farh <= upper)
    {
        cel = 5 * (farh - 32)/9;
        printf("%d\t%d\n", farh, cel);
        farh += step;
    }

    return 1;
}
int convert(int far)
{
    int cel;
    cel = 5 * (far-32)/9;
    return cel;
    
}