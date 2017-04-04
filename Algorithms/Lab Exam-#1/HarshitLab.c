#include<stdio.h>
#include<stdlib.h>
int ans=-1;

// Checking the conditions and returning values 1 or 0 for TRUE or FALSE respectively
// x is A[i] and y is A[i-1] at any given i
int solcheck(int x,int y)
{
	if(x%2==0 && x>y)
		return 1;
	else
		return 0;
}

// Main logic for the problem - Implementation of the search function using concepts of BINARY SEARCH for a O(logn) solution 
int search(int arr[], int l, int r)
{
	if(r>=l)
	{
		int mid = l + (r-l)/2;
		// If arr[mid] is even
		if(arr[mid]%2==0 && mid >= 1)
		{
			if(solcheck(arr[mid],arr[mid-1])==1)
			{
				ans=mid;
				printf("Ans=%d\n",ans);
				return search(arr,l,mid-1);
			}
			if(mid%2==0)
				return search(arr,mid+1,r);
			else
				return search(arr,l,mid-1);
		}
		// If arr[mid] is odd
		else if(mid >= 1)
		{
			if(mid%2==0)
				return search(arr,mid+1,r);
			else
				return search(arr,l,mid-1);
		}
	}
	// We reach here when no such search is possible
	return ans;
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
	int temp = search(A,0,size-1);
	if(temp != -1)
		printf("%d\n",temp);
	else
		printf("NO SUCH j POSSIBLE\n");
	return 0;
}
	
	
