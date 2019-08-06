#!/bin/sh

# Function to check if number is non-prime or not
checkNonPrime(){
   # Return code 0 means number is not prime
   # Return code 1 means number is prime
   # $1 represents the number passed to the function

   # Check if number passed is 1
   if [ $1 -eq 1 ]
   then
       # $1 is not prime, therefore, return 0
       return 0
   fi

   # $j will run from 2 to ($1 - 1)
   j=2
   # Loop till $j is less than $1
   while [ $j -lt $1 ]
   do
       # $val will be 0 if number is divisible by $j
       val=`expr $1 % $j`
       # If $val is divisible by 0 then it is not prime
       if [ $val -eq 0 ]
       then
           # $1 is not prime, therefore, return 0
           return 0
       fi
       # Increment value of $j by 1
       j=`expr $j + 1`
   done

   # If no value is returned and loop ends then that means
   # the number passed is not divisible by any other number

   # $1 is prime, therefore, return 1
   return 1
}

## Main script starts here

# Prompt user to enter value of n
echo -n "Enter the value of n: "

# Get input from the user
read n

echo -n "First $n non-prime numbers are: "
# $counter will keep track of how many non-primes
# have been echoed so far
counter=0
# $i is checked if it is prime or not
i=1
# Loop till $counter is less than $n
while [ $counter -lt $n ]
do
   # Check if $i is prime or not
   checkNonPrime $i
   # Return code 0 means $i is not prime
   # Return code 1 means $i is prime
   # $? represents return code returned by last command

   # If return code is 0 i.e. $i is not prime
   if [ $? -eq 0 ]
   then
       # Echo value of $i
       echo -n "$i "
       # One non-prime number has been echoed. So, increment $counter.
       counter=`expr $counter + 1`
   fi
   # Increment $i and then check if that is prime or not
   i=`expr $i + 1`
done
echo ""
