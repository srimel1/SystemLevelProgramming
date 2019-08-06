#!/bin/sh
# fuction to check if number is nonprime or not
# $1 is the number passed to the function
checkNonPrime(){
#checks if $1 is prime
if [ $1 -eq 1 ]
then
	return 0 #if its non then return 0
fi
# $j will go from 2 to ($1 - 1)
j=2
while [ $j -lt $1 ]
do
# $val will be 0 if number is divisible by $j
val=`expr $1 % $j`
# if $val is divisible by 0 then it is not prime
if [ $val -eq 0 ]
then
return 0
fi
# increment value of $j by 1
j=`expr $j + 1`
done
return 1
}
# Main starts here
echo -n "Enter the value of n: "
read n
echo -n "First $n nonprime numbers are: "
count=0
i=1
# Loop till $count is less than $n
while [ $count -lt $n ]
do
   checkNonPrime $i
if [ $? -eq 0 ]
   then
      echo -n "$i "
      # One nonprime number has been echoed So, increment $counter
      count=`expr $count + 1`
fi
# increment $i and then check if it is prime or not
i=`expr $i + 1`
done
echo ""
