/* 
* Algorithm to rearrange the array in a way that the 
* elements smaller or equal to the given pivot element
* occurs before it and the elements greater than it
* occur after it.

* Author:- Harshit Budhraja
* Created on 27/01/2017.
*/

#include<stdio.h>
#include<stdlib.h>

int lowercount=0;

int* initpivot(int arr[],int size,int p)
{
	int t=arr[p];
	arr[p]=arr[size-1];
	arr[size-1]=t;
	return arr;
}

// A utility function to shift LEFT a given sub-array arr[a..b]
int* shl(int arr[],int a,int b)
{
	int i=0;
	for(i=a;i<=b;i++)
	{
		arr[i]=arr[i+1];
	}
	arr[b]=0;
	return arr;
}

int getpos(int arr[],int size,int pivot)
{
	int i=0,p=-1;
	// Loop to get the position of the pivot element in the given array
	for(i=0;i<size;i++)
		if(arr[i]==pivot)
		{
			p=i;
			break;
		}
	if(p==-1)
	{
		printf("Pivot element not found in the array...exiting");
		exit(0);
	}
	// Now, we have the index of the pivot element stored in the variable 'p'
	return p;
}

int* rearrange(int arr[],int size, int pivot)
{
	int i=0,temp=0,pos=0,j=0;
	pos=getpos(arr,size,pivot);
	arr=initpivot(arr,size,pos);
	pos=getpos(arr,size,pivot);
	for(i=0;i<pos;i++)
	{	
		for(j=0;j<size;j++)
			printf("%d ",arr[j]);
		printf("\n");	
		
		if(arr[i]>pivot)
		{
			temp=arr[i];
			arr=shl(arr,lowercount,size-1);
			arr[size-1]=temp;
		}
		else
		{
			lowercount++;
		}
		pos=getpos(arr,size,pivot);
		i=lowercount-1;
	}	
			
	return arr;
}

int main()
{
	int size=0,i=0;
	scanf("%d",&size);
	int a[size];
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);
	int pivot=0;
	scanf("%d",&pivot);
	int *b=rearrange(a,size,pivot);
	for(i=0;i<size;i++)
		printf("%d ",b[i]);
	return 0;
}
