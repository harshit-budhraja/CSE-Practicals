# Shell script to build a calculator
# Date :- 31st January, 2017 
# Author:- Harshit Budhraja

clear
result=0
choice="y"
while [ $choice = "y" ]
do
	clear
	echo "                                 CALCULATOR"
	echo "1. Addition"
	echo "2. Subtraction"
	echo "3. Multiplication"
	echo "4. Division"
	echo "5. sin(x)"
	echo "6. cos(x)"
	echo "7. ln(x)"
	echo "8. log(x)"
	echo "9. sqrt(x)"
	echo "10. (e)^ x"
	echo "11. EXIT"
	read ch
	case $ch in
		# Addition
		1)
		clear
		echo "Enter number #1 --> "
		read a
		echo "Enter number #2 --> "
		read b
		result=$(echo "$a + $b" | bc)
		echo "$a + $b = $result"
		;;
		
		# Subtraction
		2)
		clear
		echo "Enter number #1 --> "
		read a
		echo "Enter number #2 --> "
		read b
		result=$(echo "$a - $b" | bc)
		echo "$a - $b = $result"
		;;
		
		# Multiplication
		3)
		clear
		echo "Enter number #1 --> "
		read a
		echo "Enter number #2 --> "
		read b
		result=$(echo "$a * $b" | bc)
		echo "$a * $b = $result"
		;;
		
		# Division
		4)
		clear
		echo "Enter number #1 --> "
		read a
		echo "Enter number #2 --> "
		read b
		result=$(echo "$a / $b" | bc)
		echo "$a / $b = $result"
		;;
		
		# sin(x)
		5)
		clear
		echo "Enter number --> "
		read a
		result=$(echo "s($a)" | bc -l)
		echo "sin($a) = $result"
		;;
		
		# cos(x)
		6)
		clear
		echo "Enter number --> "
		read a
		result=$(echo "c($a)" | bc -l)
		echo "cos($a) = $result"
		;;
		
		# ln(x)
		7)
		clear
		echo "Enter number --> "
		read a
		result=$(echo "l($a)" | bc -l)
		echo "ln($a) = $result"
		;;
		
		# log(x)
		8)
		clear
		echo "Enter number --> "
		read a
		result=$(echo "l($a) / l(10)" | bc -l)
		echo "log($a) = $result"
		;;
		
		# sqrt(x)
		9)
		clear
		echo "Enter number --> "
		read a
		result=$(echo "sqrt($a)" | bc -l)
		echo "sqrt($a) = $result"
		;;
		
		# (e)^ x
		10)
		clear
		echo "Enter number --> "
		read a
		result=$(echo "e ($a)" | bc -l)
		echo "(e) ^ $a = $result"
		;;
		
		11)
		exit 0
		;;
		
		*)
		echo "INVALID CHOICE"
		;;
	esac
	echo "Continue [y/n] --> "
	read choice
	if [ $choice != "y" ]
	then
	    exit 0
	fi
done
