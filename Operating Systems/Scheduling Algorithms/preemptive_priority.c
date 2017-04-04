/*
* -----------------------------------------------------*
* To implement preemptive priority scheduling algorithm
* and calculate the average turn-around-time and the
* average waiting time.
* -----------------------------------------------------*
* INPUT/OUTPUT SPECS
* [a] Take the number of processes 'N' as input from the user.
* [b] Take arrival times, CPU Burst times and priorities of
      each of these 'N' processes from the user.
* -----------------------------------------------------*
* SAMPLE TEST CASE
* | Process | Arrival Time | CPU Burst Time | Priority  |
* |---------|--------------|----------------|-----------|
* |    P1   |	0	   |	4	    |	1	|
* |    P2   |	1	   |	2	    |	2	|
* |    P3   |	1	   |	3	    |	4	|
* |    P4   |	2	   |	5	    |	5	|
* |    P5   |	2	   |	1	    |	2	|
* |    P6   |	3	   |	2	    |	3	|
* |---------|--------------|----------------|-----------|
* Higher priority is with a higher integer value.
* P[5] > P[1].
*
* Sample Input Answer:- 10.33 seconds and 7.5 seconds
*
* Author:- Harshit Budhraja
* Date:- 04/04/2017
*/

#include<stdio.h>

// Structure Definition
struct Process
{
	int arrival;
	int cpu_burst;
	int priority;
	
	int completed;
	int runtime;
	int iscompleted;
};


/* ----------------------------------------------------------- *
*  ---------------DRIVER FUNCTION FOR THE PROGRAM------------- */
int main(void)
{
	// Declarations of initial variables
	int N=0,i=0;
	int tat=0,wt=0; // tat=>Average turn-around-time & wt=>Average waiting time
	
	// IO Operations
	printf("N=> ");
	scanf("%d",&N);
	
	// Instantiate the structure with 'N' number of processes
	struct Process P[N+1];
	
	// init() structure
	for(i=1;i<=N;i++)
	{
		P[i].arrival=0;
		P[i].cpu_burst=0;
		P[i].priority=0;
		P[i].completed=0;
		P[i].runtime=0;
		P[i].iscompleted=0;
	}
	
	// Input the specifications for these processes
	printf("| Process |\n| Arrival Time | CPU Burst Time | Priority |\n");
	for(i=1;i<=N;i++)
	{
		printf("\n|   P[%d]  |\n",i);
		scanf("%d %d %d",&P[i].arrival,&P[i].cpu_burst,&P[i].priority);
	}
	
	// Scheduling starts
	int endtime=0;
	for(i=1;i<=N;i++)
		endtime+=P[i].cpu_burst;
	int time=0;
	int chp=0;	// current highest priority
	int selected=0;
	for(time=0;time<=endtime;time++)
	{
		if(P[selected].runtime==P[selected].cpu_burst)
		{
			P[selected].completed=time;
			P[selected].iscompleted=1;
			chp=0;
		}
		for(i=1;i<=N;i++)
		{
			if(!P[i].iscompleted)
			{
				// Only the processes which have arrived before or at current time
				if(time>=P[i].arrival)
				{
					if(P[i].priority > chp)
					{
						chp=P[i].priority;
						selected=i;
					}
					else if(P[i].priority == chp)
					{
						if(P[i].arrival < P[selected].arrival)
							selected=i;
					}
				}
				
			}
			else continue;
		}
		P[selected].runtime++;
	}
	
	// Formula for calculation
	float sum_tat=0,sum_wt=0;
	for(i=1;i<=N;i++)
	{
		sum_tat += (P[i].completed-P[i].arrival);
		sum_wt += (P[i].completed - P[i].arrival - P[i].cpu_burst);
		//printf("\nP[%d] = %d\n",i,P[i].completed);
		//printf("%f\n",sum_tat);
	}
	//printf("%f\n",sum_tat);
	printf("\n\nAverage turn-around-time = %f\nAverage waiting time = %f\n",sum_tat/N,sum_wt/N);

	return 0;
}

