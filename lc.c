#include <math.h>
#include <stdlib.h>
#include <stdio.h>

float balance()
{
    float B, r, n, SI;

    /* Input principle, rate and time */
    printf("Enter amount of loan : ");
    scanf("%f", &B);

    printf("Enter interest rate per year : ");
    scanf("%f", &r);

    printf("Enter number of payments : ");
    scanf("%f", &n);

    /* Calculate simple interest */
    interest =B(n-1)*r
    principal = 
    SI = (P * r * n) / 100;
    /* Print the resultant value of SI */
    printf("Monthly payments should be  %f", SI);
    printf("\n");
     printf("================AMORTIZATION SCHEDULE==================\n");
    printf("%5s %10s %10s %10s %10s\n", "#", "Payment", "Principal", "Interest", "Balance");

   return 0;
}
int main()
{
    float principal, interstRate, monthlyInterestRate;
    float emi, startingBalance, interest, principalPaid, endingBalance;
    int numOfMonths, month;
    float interestArr[30], principalPaidArr[30], endingBalanceArr[30];

    //Reading principal amount
    printf("\n Enter Amount of Loan: ");
    scanf("%f", &principal);

   //Reading interest rate
   printf("\n Enter Interest rate per year: ");
    scanf("%f", &interstRate);

   //Reading number Of months
   printf("\n Enter number of payments: ");
    scanf("%d", &numOfMonths);

   //Converting interest rate into Monthly
   monthlyInterestRate = (float)(interstRate / (12*100.0));

   //Calculating EMI
   emi = principal * (monthlyInterestRate / (1 - pow( (1 + monthlyInterestRate) , (-numOfMonths) )));

   //Consider starting balance as principal
   startingBalance = principal;

    //Printing Monthly payment
   printf("\n\n Monthly Payment: $%.2f \n", emi);

       //Calculating loan schedule
    for(month = 1; month <= numOfMonths; month++)
    {
        //Calculating interest
       interestArr[month-1] = (startingBalance * monthlyInterestRate);

       //Calculating principal
       principalPaidArr[month-1] = emi - interestArr[month-1];

       //Calculating ending balance
       endingBalanceArr[month-1] = (startingBalance - principalPaidArr[month-1]);

       //Updating starting balance with ending balance
       startingBalance = endingBalanceArr[month-1];
    }

   //Printing headers
   printf("\n %10s %14s %10s %10s \n", " Payment ", " Principal ", " Interest ", " Balance ");

   //Calculating loan schedule
    for(month = 1; month <= numOfMonths; month++)
    {
       //Printing result
       printf("\n %6d \t $%-10.2f $%-10.2f $%-12.2f ", month, principalPaidArr[month-1], interestArr[month-1], endingBalanceArr[month-1]);
    }

    //Printing final payment
    printf("\n\n Final Payment: $%.2f \n", emi);

   printf("\n");
    return 0;
}