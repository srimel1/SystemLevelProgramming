    #include<stdio.h>
    #include<math.h>
    int main(void)
    {
      double inst=0.4, loan_amt=0.56, pay=0.34;   
      double mon = (inst/1200);
      double quarterly = (inst/400);
      double Half = (inst/200);
      double annual = (inst/100);
      //Mothly  
      double ad = 1 + mon;      
      double amt,amt_mon,amt2; 
      amt_mon = -1*((log( 1 - ((mon * loan_amt) / pay))));
      amt2 =(log(ad));  
      amt = (amt_mon / amt2); 
      printf("\nNumber of Payments based on monthly : %lf",amt); 
      
      //Quarterly
        
         ad = 1 + quarterly;
      double amt_quart;
      amt_quart = (( -log( 1 - ((quarterly * loan_amt) / pay))));
      amt = (amt_quart / amt2);
      printf("\nNumber of Payments based on quarterly : %lf",amt); 
        
      //HalfYearly
         ad = 1 + Half;
      double amt_half;
      amt_half = (( -log( 1 - ((Half * loan_amt) / pay))));
      amt = (amt_half / amt2);
      printf("\nNumber of Payments based on HalfYearly : %lf",amt); 
        
      //Annually
         ad = 1 + annual;
      double amt_ann;
      amt_ann = (( -log( 1 - ((annual * loan_amt) / pay))));
      amt = (amt_ann / amt2);
      printf("\nNumber of Payments based on Annually : %lf",amt);
      return 0;
        
    }
        