#include<stdio.h>
#include<stdlib.h>

// Checking the conditions and returning values 1 or 0 for TRUE or FALSE respectively
// x is A[i] and y is A[i-1] at any given i
int solcheck(int x,int y)
{
	if(x%2==0 && x>y)
		return 1;
	else
		return 0;
}

// Main logic for the problem - Implementation of the search function
int search(int arr[], int n)
{
	int i=0;
	for(i=1;i<n;i++)
	{
		if(solcheck(arr[i],arr[i-1])==1)
			return i;
	}
}
		 
int main()
{
	// Declaration of variables
	int size=0,i=0;
	// Accepting the input 'n'......size<=>2n
	scanf("%d",&size);
	// Declaring the array and accepting test cases for the array components
	int A[size];
	for(i=0;i<size;i++)
		scanf("%d",&A[i]);
	int temp = search(A,size);
	if(temp != -1 && temp != 0)
		printf("%d\n",temp);
	else
		printf("NO SUCH j POSSIBLE\n");
	return 0;
}
	
	
