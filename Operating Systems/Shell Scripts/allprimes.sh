# Shell script to print all prime numbers from 1 to 100
# Date :- 31st January, 2017 
# Author:- Harshit Budhraja

flag=0
rem=0
echo "2"
for (( i=3 ; i <= 100 ; i++ ))
do	
	upper=$(( $i / 2 ))
	for (( j=2 ; j <= $upper ; j++ ))
	do 
	     	rem=$(( $x % $j ))
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
		echo "$x"
	fi
done
