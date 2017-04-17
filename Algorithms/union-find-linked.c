/* To implement UNION FIND using linked list representation
* Author:- Harshit Budhraja
* Date:- 07/04/2017
* Completed on:- 17/04/2017
*/

#include<stdio.h>
#include<stdlib.h>

// The structure definition for a list
struct List
{
	struct Element *head;
	struct Element *tail;
	int size;
};

// The structure definition for UNION FIND data structure
struct Element
{
	int value;	// The key value
	struct List *rep;	// Pointer to the representative of the list
	struct Element *next;	// Pointer to the immidiate next element in the list
}


// make_set() takes a value as input and creates an element and a list
struct List *make_set(int x)
{	
	// Creating the element
	struct Element ptr=(struct Element *)malloc(sizeof(struct Element));
	ptr->value=x;
	ptr->next=NULL;
	ptr->rep=ptr;
	
	// Appending it to a list
	struct List L=(struct List *)malloc(sizeof(struct List));
	if(L==NULL)
	{	
		L->size++;
		L->head=ptr;
		L->tail=ptr;
	}
	return L;
}

// find_set() takes in a pointer to an element and returns the pointer to its representative element
struct List *find_set(struct Element *x)
{
    return x->rep->head;
}

// union() takes input as pointers to two elements
struct List union(struct Element *x, struct Element *y)
{
    // h1 and h2 are the pointers to representatives of the list containing the elements x and y
    struct List *h1=find_set(x);
    struct List *h2=find_set(y);
    
    // Now we find the smaller of the two lists and carry out the union operation appropriately
    if(h1->size > h2->size)
    {
        /********************* h1 > h2 **************************/        
        
        // Join the smaller list behind the bigger list
        h1->tail->next=h2->head;
        // Update the *tail of the bigger list
        h1->tail=h2->tail;
        // Update the size of the bigger list
        h1->size+=h2->size;
        // Update the size of the smaller list
        h2->size=0;
        
        // Change the representative pointers of all elements in the smaller list
        // *ptr is an interator that iterates over the smaller list
        struct Element *ptr = h2->head;
        while(ptr!=NULL)
        {
            ptr->rep=h1;
            ptr=ptr->next;
        }
        
        // Remove the head of the smaller list
        free(h2);
        
        // Return the pointer to the larger list
        return h1;
    }
    else
    {
        /********************* h1 < h2 **************************/
        
        // Join the smaller list behind the bigger list
        h2->tail->next=h1->head;
        // Update the *tail of the bigger list
        h2->tail=h1->tail;
        // Update the size of the bigger list
        h2->size+=h1->size;
        // Update the size of the smaller list
        h2->size=0;
        
        // Change the representative pointers of all elements in the smaller list
        // *ptr is an interator that iterates over the smaller list
        struct Element *ptr = h1->head;
        while(ptr!=NULL)
        {
            ptr->rep=h2;
            ptr=ptr->next;
        }
        
        // Remove the head of the smaller list
        free(h1);
        
        // Return the pointer to the larger list
        return h2;
    }
}

/* Driver function for the program
int main(void)
{
	struct Element *e=make_set(3);
	printf("%d\n",e->value);
	struct Element *e2=make_set(4);
	printf("%d\n",e2->value);
	printf("%d\n",L->head->value);
	return 0;
}*/
