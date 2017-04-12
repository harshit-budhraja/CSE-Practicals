/*
* -----------------------------------------------------*
* To implement First come First serve scheduling algorithm
* and calculate the average turn-around-time and the
* average waiting time.
* -----------------------------------------------------*
* INPUT/OUTPUT SPECS
* [a] Take the number of processes 'N' as input from the user.
* [b] Take arrival times and CPU Burst times of
      each of these 'N' processes from the user.
* -----------------------------------------------------*
* SAMPLE TEST CASE
* | Process | Arrival Time | CPU Burst Time |
* |---------|--------------|----------------|
* |    P1   |	0	   |	5	    |
* |    P2   |	2	   |	4	    |
* |    P3   |	3	   |	7	    |
* |    P4   |	5	   |	6	    |
* |---------|--------------|----------------|
*
* Sample Input Answer:- 10.5 seconds and 5 seconds
*
* Author:- Harshit Budhraja
* Date:- 12/04/2017 16:25hrs IST
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXQ 100

// Number of processes
int N=0;

// The queue implementation for the Ready queue of the incoming/arriving processes
int ready_queue[MAXQ];

// Structure Definition
struct Process
{
	int arrival;
	int cpu_burst;
	
	int completed;
	int runtime;
	int iscompleted;
};

// Iterators for the ready queue
int head=-1, tail=-1;

// Utility function to check if the queue is full
int isFull()
{
	if(tail==N-1)
		return 1;
	else
		return 0;
}

// Initializing all elements of the ready queue as -1 initially
// -1 signifies no process in that location and process id starts from 1
void init_queue()
{
	int i=0;
	for(i=0;i<N;i++)
		ready_queue[i]=-1;
}

// To append a new process inside this queue
void schedule_process(int pid)
{
	if(isFull())
	{
		//If the queue is full
		printf("APPEND ERROR: Insufficient memory with the Ready Queue\n");
		exit(0);
		
	}
	else if(head == -1)
	{
		//Insert the first element
		head=tail=0;
		ready_queue[tail]=pid;
	}
	else
	{
		tail++;
		ready_queue[tail]=pid;
	}
}

// Utility process to select the process from the ready queue - DEQUEUE() basically
// Returns -1 if the queue is empty and pid of the process to be executed next otherwise
int run_process()
{
	if(head == -1)
		return -1;
	int pid=ready_queue[head];
	ready_queue[head]=-1;
	if(head==tail)
	{
		head=tail=-1;
	}
	else
		head++;
	
	return pid;
}


/* ----------------------------------------------------------- *
*  ---------------DRIVER FUNCTION FOR THE PROGRAM------------- */
int main(void)
{
	init_queue();
	// Declarations of initial variables
	int i=0,temp=-1;
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
		P[i].completed=0;
		P[i].runtime=0;
		P[i].iscompleted=0;
	}
	
	// Input the specifications for these processes
	printf("| Process |\n| Arrival Time | CPU Burst Time |\n");
	for(i=1;i<=N;i++)
	{
		printf("\n|   P[%d]  |\n",i);
		scanf("%d %d",&P[i].arrival,&P[i].cpu_burst);
	}
	
	// Scheduling starts
	int endtime=0;
	for(i=1;i<=N;i++)
		endtime+=P[i].cpu_burst;
	//printf("End time for analysis = %d secs\n",endtime);
	int time=0;
	int selected=-1;
	for(time=0;time<=endtime;time++)
	{
		// Adding the processes to ready queue as soon as they arrive
		for(i=1;i<=N;i++)
		{
			if(time==P[i].arrival && P[i].iscompleted==0)
			{
				schedule_process(i);
				printf("ARRIVAL: Process P%d arrived just now at time #%d seconds\n",i,time);
			}	
		}
		if(time==0)
			selected=run_process();
		
		/*********************** CPU Simulation ***********************/
		printf("RUNNING: At time #%d seconds, P%d is running...\n",time,selected);
		
		if(P[selected].runtime==P[selected].cpu_burst)
		{
			P[selected].completed=time;
			P[selected].iscompleted=1;
			printf("COMPLETION: Process P%d completed just now at time #%d seconds\n",selected,time);
			selected=run_process();
			if(selected!=-1)
				printf("SWITCH: Process P%d is selected and brought to the CPU\n",selected);
		}
		if(!P[selected].iscompleted)
			P[selected].runtime++;
	}
	
	// Formula for calculation
	float sum_tat=0,sum_wt=0;
	for(i=1;i<=N;i++)
	{
		sum_tat += (P[i].completed-P[i].arrival);
		sum_wt += (P[i].completed - P[i].arrival - P[i].cpu_burst);
		printf("\nP[%d] = %d",i,P[i].completed);
		//printf("%f\n",sum_tat);
	}
	//printf("%f\n",sum_tat);
	printf("\n\nAverage turn-around-time = %f\nAverage waiting time = %f\n",sum_tat/N,sum_wt/N);

	return 0;
}

