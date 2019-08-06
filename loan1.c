
// EMI Calculator program in C 
#include <math.h> 
#include <stdio.h> 
  
// Function to calculate EMI 
float emi_calculator(float p, float r, float t) 
{ 
    float emi; 
  
    r = r / (12 * 100); // one month interest 
    t = t * 12; // one month period 
    emi = (p * r * pow(1 + r, t)) / (pow(1 + r, t) - 1); 
  
    return (emi); 
} 
  
// Driver Program 
int main() 
{ 
    float principal, rate, time, emi; 
    principal = 10000; 
    rate = 10; 
    time = 2; 
    emi = emi_calculator(principal, rate, time); 
    printf("\nMonthly EMI is= %f\n", emi); 
  
    return 0; 
} 
