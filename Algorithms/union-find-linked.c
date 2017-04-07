/* To implement UNION FIND using linked list representation
* Author:- Harshit Budhraja
* Date:- 07/07/2017
*/

#include<stdio.h>
#include<stdlib.h>

// The structure definition for a list
struct List
{
	struct Element *head;
	struct Element *tail;
	int size;
}*L;

// The structure definition for UNION FIND data structure
struct Element
{
	int value;	// The key value
	struct Element *rep;	// Pointer to the representative of the list
	struct Element *next;	// Pointer to the immidiate next element in the list
}*ptr;

struct Element *make_set(int x)
{	
	// Creating the element
	ptr=(struct Element *)malloc(sizeof(struct Element));
	ptr->value=x;
	ptr->next=NULL;
	ptr->rep=ptr;
	
	// Appending it to a list
	L=(struct List *)malloc(sizeof(struct List));
	if(L==NULL)
	{	
		L->size++;
		L->head=ptr;
		L->tail=ptr;
	}
	else
	{
		L->size++;
		L->tail=ptr;
	}
	return ptr;
}

// Driver function for the program
int main(void)
{
	struct Element *e=make_set(3);
	printf("%d\n",e->value);
	struct Element *e2=make_set(4);
	printf("%d\n",e2->value);
	printf("%d\n",L->head->value);
	return 0;
}
