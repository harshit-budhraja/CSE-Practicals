/*
* To denote the different operations on STACKS 
* Author:- Harshit Budhraja
*/
#include<stdio.h>
#define MAXLEN 100

typedef struct
{
	char element[MAXLEN];
	int top;
}stack;
	   	

stack init()
{
    	stack S;
    	S.top = -1;
	return S;
}
	   	

int isEmpty(stack S)
{
	return (S.top == -1);
}


int isFull(stack S)
{
	return (S.top == MAXLEN - 1);
}
   	
//Retrieval of topmost element of stack   	
char TOP(stack S)
{
	if (isEmpty(S)) 
	{
        	printf("Empty stack\n");
         	return '\0';
      	}
      	return S.element[S.top];
}

//Insert operation on stack
stack PUSH(stack S,char ch)
{
	if (isFull(S)) 
	{
        	printf("Full stack\n");
         	return S;
      	}
      	++S.top;
      	S.element[S.top] = ch;
      	return S;
}

//Delete operation on stack
stack POP(stack S)
{
      	if (isEmpty(S)) 
	{
         	printf("Empty stack\n");
         	return S;
      	}
      	--S.top;
      	return S;
}

//Print
void print(stack S)
{
	int i;
	for(i = S.top; i >= 0; --i) 
		printf("%c,",S.element[i]);
}
  	 
//Driver function for the program  	 
void main()
{
	stack S;
	S=init(); 
	printf("Current stack : "); 
	print(S); 
	printf(" with top = %c.\n", TOP(S));
	S=PUSH(S,'d'); 
	printf("Current stack : "); 
	print(S); 
	printf(" with top = %c.\n", TOP(S));
	S =PUSH(S,'f'); 
	printf("Current stack : "); 
	print(S); 
	printf(" with top = %c.\n", TOP(S));
}
