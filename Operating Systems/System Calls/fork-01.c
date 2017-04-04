/*
* PROGRAM  fork-01.c                                              
* This program illustrates the use of fork() and getpid() system
* calls.  Note that write() is used instead of printf() since  
* getpid() is buffered while fork() is not.
* Author:- Harshit Budhraja
* Date:- 04/04/2017 
*/

#include<stdio.h>
#include<string.h>
#include<sys/types.h>

#define MAX_COUNT 200
#define BUF_SIZE 100

void main()
{
     pid_t pid;
     int i;
     char buf[BUF_SIZE];

     fork();
     pid=getpid();
     for(i=1;i<=MAX_COUNT;i++) 
     {
          sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
          write(1, buf, strlen(buf));
     } 
}

