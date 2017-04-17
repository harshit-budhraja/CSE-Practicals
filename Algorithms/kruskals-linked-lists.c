/*
* Author:- Harshit Budhraja
* Date:- 17/04/2017 Monday Evening Extra Lab [6pm to 8pm]
* To implement the kruskal's algorithm using the linked-list representation
* TODO:- Implement the sort function
*/

#include<stdio.h>
#include<stdlib.h>
#define M 25

int u[M],v[M],w[M],edges=0;

/*******************************MERGE SORT = O(n.log(n)) complexity****************************/
void merging(int low, int mid, int high) 
{
   int l1, l2, i;
   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) 
   {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int low, int high) 
{
   int mid;
   if(low < high) 
   {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } 
   else 
   { 
      return;
   }   
}
/***********************************************************************************************/

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
};


// make_set() takes a value as input and creates an element and a list
struct List *make_set(int x)
{	
	// Creating the element
	struct Element *ptr=(struct Element *)malloc(sizeof(struct Element));
	ptr->value=x;
	ptr->next=NULL;
	ptr->rep=ptr;
	
	// Appending it to a list
	struct List *L=(struct List *)malloc(sizeof(struct List));
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
struct List *union_set(struct Element *x, struct Element *y)
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

void input()
{
    printf("The accepted input is as follows:- \n-----\nU V W\n-----\n");
    while(scanf("%d %d %d",&u[edges],&v[edges],&w[edges])==3)
    {
        printf("%d %d %d\n",u[edges],v[edges],w[edges]);
        edges++;
    }
    printf("Total number of EDGES received as input = %d\n",edges);
}

// Driver function for the program
int main()
{
    input();
    
    return 0;
}
