# Shell script to check for prime or composite
# Date :- 31st January, 2017 
# Author:- Harshit Budhraja

echo "Enter any number:- "
read x
if [ $x -eq 1 ]
then
	echo "NEITHER PRIME NOR COMPOSITE"
	exit 0
fi
if [ $x -eq 2 ]
then
	echo "PRIME"
	exit 0
fi
upper=$(( $x / 2 ))
for (( i=2 ; i <= $upper ; i++ ))
do 
     	rem=$(( $x % $i ))
	if [ $rem -eq 0 ]
	then
		flag=0
		break
	else
		flag=1
	fi
done
if [ $flag -eq 1 ]
then
	echo "PRIME"
	exit 0
else
	echo "NOT PRIME"
	exit 0
fi
