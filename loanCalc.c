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
payments[100];
/*********************************************************************/
int main()
{
    double balance, interestRate;

    int n; /* number of payments */

    /* A = payments amount per period (monthly payment) */
    /* B = initial balance (loan amount) */
    /* r = interest rate per period */
    /* n = total number of paments or periods */
    
    double A, r;

    /* get data from user */
    printf("Enter amount of loan : $ ");
    scanf("%lf", &balance);
    printf("Enter interest rate per period : %% ");
    scanf("%lf", &interestRate);
    printf("Enter number of payments : $ ");
    scanf("lf", &n);

    /* calculating interest per month */
    r = interest / 12;

    /* calculating monthly payment */
    A = balance * ( (r * pow(1 + r, n) ) / (pow(1 + r, n) - 1) );

    /* first object is the */
    payments[0].B = balance;
    printf("\nMonthly payment should be $%.2f\n", A);
    printf("================AMORTIZATION SCHEDULE==================\n");
    printf("%5s %10s %10s %10s %10s\n", "#", "Payment", "Principal", "Interest", "Balance");
    )





}