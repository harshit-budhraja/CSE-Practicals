# Shell script to check for string palindromes
# Date :- 31st January, 2017 
# Author:- Harshit Budhraja

echo "Enter a String:- "
read string
i=0
len=${#string}
mid=$(($len/2))
while [ $i -lt $mid ]
	do
		if [ "${string:$i:1}" != "${string: -$(($i+1)):1}" ]
		then
			echo "\"$string\" IS NOT a Palindrome"
			exit 0
		fi
		i=$(($i+1))
	done
echo "\"$string\" IS a Palindrome"
