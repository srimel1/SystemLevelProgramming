#include <stdio.h>
int main(void)
{
    int num1, denom1, num2, denom2;
    int resultNum, resultDenom;
    float test;

    /* prompt user to enter desired fractions */
    printf("Enter first fraction: \n");
    scanf("%d/%d", &num1, &denom1);

    printf("Enter second fraction: \n");
    scanf("%d/%d", &num2, &denom2);

    /* calculate addition of two fractions */
    resultNum = num1 * denom2 + num2 * denom1;
    resultDenom = denom1 * denom2;


    /* check if sum is equal to 1 */
    if (resultNum == resultDenom)
    {
    printf("The sum is 1\n");
    }
    else
    {
    printf("The sum is %d/%d\n", resultNum, resultDenom);
    }
    return 0;

}