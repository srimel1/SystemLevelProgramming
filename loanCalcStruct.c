#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct loan
{
    double INT; /* interest */
    double B; /* balance */
    double P; /* principle */
}
/*********************************************************************/
payments[100]; /* structure array to hold payments */
/*********************************************************************/
int main()
{
    double balance, interestRate;

    int n; /* number of payments */

    double A, r;

    /* get data from user */
    printf("\nEnter amount of loan : $ ");
    scanf("%lf", &balance);
    printf("Enter interest rate per period : %% ");
    scanf("%lf", &interestRate);
    printf("Enter number of payments : ");
    scanf("%d", &n);

    /* calculating interest per month */
    r = interestRate / 1200;

    /* calculating monthly payment */
    A = balance*((r*pow(1+r,n))/(pow(1+r,n)-1)); // A = monthly payment

    /* first object is the initial balance */
    payments[0].B = balance; // B = balance

    /* headers */
    printf("\nMonthly payment should be $%.2f\n\n", A);
    printf("=================Amortization Schedule====================\n\n");
    printf(" %-8s %10s %13s %10s %10s \n", "#", " Payment ", " Principal ", " Interest ", " Balance ");
    
    int i; /* months */

    for(int i = 1; i <= n; i++)
    {
        /* interest, payments, principal, new balance calculations */
        payments[i].INT = payments[i - 1].B * r; // interest
        payments[i].P = A - payments[i].INT; // principal
        payments[i].B = payments[i - 1].B - payments[i].P; // balance

        /* format and print */
        printf("\n %-10d $%-10.2lf $%-10.2lf $%-10.2lf $%-12.2lf ", i, A, payments[i].P, payments[i].INT, payments[i].B);
    }

printf("\n\n");
return 0;
}