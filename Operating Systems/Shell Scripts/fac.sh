# Shell script to find factorial of a number
# Date :- 31st January, 2017 
# Author:- Harshit Budhraja

echo "Enter any number:- "
read x
product=1
for (( i=x ; i >= 1 ; i-- ))
do
	product=$(($product * $i))
done
echo "$x! = $product"
