# !/bin/bash
y=`expr $1 - 3`
x=`expr $y % 12`


if [ $1 -gt 1947 ]
then
	echo -ne $1 "was the year of "
	case $x in
	1) echo Rat ;;
	2) echo Ox ;;
	3) echo Tiger ;;
	4) echo Rabbit ;;
	5) echo Dragon ;;
	6) echo Snake ;;
	7) echo Horse ;;
	8) echo Goat ;;
	9) echo Monkey ;;
	10) echo Rooster ;;
	11) echo Dog ;;
	12) echo pig ;;
	*) echo error ;;
	esac
	
else
	echo "Please enter a year after 1947"
fi
