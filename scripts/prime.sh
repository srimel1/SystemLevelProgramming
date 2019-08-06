#!/bin/sh
prime=0
#ask for value of n
echo -n "Enter a value for n: "
#store the input
read n
echo -n "First $n prime numbers are: "
#Display first prime number, 3
echo -n "2 "
#set variable count to 1
count=1
#start a for loop unto the count variable
for((x=3;$count<n;))
do
#start a for loop from 2 to the value of x
for((j=x-1;j>=2;))
do
#check for factors and set the value of flag
if [ `expr $x % $j` -ne 0 ] ; then
prime=1
else 
prime=2
break
#end the for loop
fi

j=`expr $j - 1`
done
#check if the number is prime
if [ $prime -eq 1 ] ; then
#display the number
echo -n "$x "
#increment the count
count=`expr $count + 1`
fi
x=`expr $x + 1`
done
echo ""



#!/bin/bash
echo -n "Enter a year: "
read n
int i
for(
