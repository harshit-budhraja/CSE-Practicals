# Factorial script using user-defined functions
# Date:- 31st January, 2017
# Author:- Harshit Budhraja

fac() {
	x=$1
	product=1
	for (( i=x ; i >= 1 ; i-- ))
	do
		product=$(($product * $i))
	done
	echo "$x! = $product"
}

echo "Enter any number:- "
read x
fac $x
