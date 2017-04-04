/*
* Author:- Harshit Budhraja
* Date:- 24th March, 2017
* Problem:- Interval Scheduling
* Input:- Start times and Finish times of classrooms
* Output:- Minimum number of classrooms required for efficiently scheduling these classes
*/

#include<stdio.h>
#include<stdlib.h>

struct myclass
{
	int time;
	int isstart;
};

// Utility function to print the start and finish time of first 'n' classes in the structure
// To call it, use like printclass(c,t);
void printclass(struct myclass c1[], int n)
{
	int i=0;
	for(i=0;i<2*n;i++)
	{
		printf("%d ",c1[i].time);
		if(c1[i].isstart==0)
			printf("\n");
	}
	
}

// To swap the ith and jth element and return back the object
// Use it as swap(c,0,1);
struct myclass *swap(struct myclass c1[],int i,int j)
{
	int temp;
	temp=c1[i].time;
	c1[i].time=c1[j].time;
	c1[j].time=temp;
	temp=c1[i].isstart;
	c1[i].isstart=c1[j].isstart;
	c1[j].isstart=temp;
	return c1;
}

// A sorting function specially designed for this problem based on the concepts of Lexicographic sorting
struct myclass *sortclasses(struct myclass c1[],int n)
{
	int i,j;
	for(i=0;i<2*n;i++)
	{
		for(j=i+1;j<2*n;j++)
		{
			if(c1[i].time > c1[j].time)
				swap(c1,i,j);
			else if(c1[i].time==c1[j].time && c1[j].isstart==1)
				swap(c1,i,j);
		}
	}
	return c1;
}

// Driver function of the program
void main()
{
	int t=0;	// Total number of class details to be entered by the user
	printf("Enter total number of lectures -> ");
	scanf("%d",&t);
	struct myclass c[2*t];
	// Input from the user - Format as Start_time Finish_time
	int i;
	printf("INPUT\n");
	for(i=0;i<2*t;i++)
	{
		scanf("%d",&c[i].time);
	}
	
	// All the time values in positions 0,2,4,6... have isstart=1
	for(i=0;i<2*t;i++)
	{
		if(i%2==0)
			c[i].isstart=1;
		else
			c[i].isstart=0;
	}
	
	sortclasses(c,t);
	
	/*printf("Sorted order of given timings formatted as time<isstart>\n");
	for(i=0;i<2*t;i++)
	{
		printf("%d<%d> ",c[i].time,c[i].isstart);
	}
	printf("\n");*/
	
	int counter=0,max=0;
	
	// Now we have to iterate over the time values and for every start time, increment the counter & decrement it for finish time
	for(i=0;i<2*t;i++)
	{
		if(c[i].isstart==1)
			counter++;
		else
			counter--;
		if(counter>max)	max=counter;
	}
	
	printf("\nOUTPUT\n%d\n",max);
	printf("\nNOTE:- Assuming that if a class starts exactly after another class ends,\n       they CANNOT be scheduled in the same classroom.\n\n");
	
}
