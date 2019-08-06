#!/bin/sh
check(){
if[$1-eq1]
then
return 0
fi
j=2
while [ $j -lt $1 ]
do
val ='expr $1%$j'
if[ $val -eq 0]
then
return 0
fi
j='expr $j+1'
done
return 1
}
echo -n "Enter the value of n: "
read n
echo -n "First $n non-prime numbers are:  "
counter =0
i=1
while [ $counter -lt $n ]
do
	checkNonPrime $i
   if [ $? -eq 0 ]
   then
echo -n "$i "
  counter=`expr $counter + 1`
   fi
   i=`expr $i + 1`
done
echo ""

