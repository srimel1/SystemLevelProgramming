#include <stdio.h>

#include <stdlib.h>

#include <math.h>

// declaring struct loan

struct loan{

double INT; // interest

double B; // balance

double P; // principle

} object[100]; // creating 100 loan objects

int main() {

double loanAmount,interestRatePerYear;

// Number of payments

int n;

// A: Payment amount per period

// r: interest rate per period

double A,r;

printf("Enter amount of loan : $ ");

scanf("%lf",&loanAmount);

printf("Enter interest rate per year : %% ");

scanf("%lf",&interestRatePerYear);

printf("Enter number of payments : ");

scanf("%d",&n);

// Rate of interest
r = interestRatePerYear/1200;

// Amount payable in a month

A=loanAmount*((r*pow(1+r,n))/(pow(1+r,n)-1));

object[0].B = loanAmount;

// printing the monthly calculated payment

printf("\nMonthly payment should be $%.2f\n", A);

printf("===================Amortization Schedule============================\n\n");

printf("# \t Payment \t Principle \t Interest \t Balance\n");

int i;

for(i = 1; i <= n; i++) {

object[i].INT = object[i - 1].B * r; // calculating the interest on each iteration

object[i].P = A - object[i].INT; // subtracting interest from amount and assigning it as Principle

object[i].B = object[i - 1].B - object[i].P; // setting balance as balance - principle

printf("%d \t $%0.2lf \t $%0.2lf \t $%0.2lf ", i, A, object[i].P, object[i].INT);

// For output alignment

if(object[i].INT / 10.0 < 1.0)

printf("\t\t $%0.2lf", object[i].B);

else

printf("\t $%0.2lf", object[i].B);

printf("\n");

}

return 0;

}