# Shell script to check if the number is positive or negative
# Date :- 31st January, 2017 
# Author:- Harshit Budhraja

echo "Enter any number:- "
read x
if [ $x -lt 0 ]
then
	echo "NEGATIVE"
else 
	echo "POSITIVE"
fi
