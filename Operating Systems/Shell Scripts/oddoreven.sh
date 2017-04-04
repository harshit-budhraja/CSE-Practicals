# Shell script to state whether the number is even or odd
# Date :- 31st January, 2017 
# Author:- Harshit Budhraja

echo "Enter any number:- "
read x
rem=$(( $x % 2 ))
if [ $rem -eq 0 ]
then
	echo "EVEN"
else 
	echo "ODD"
fi
