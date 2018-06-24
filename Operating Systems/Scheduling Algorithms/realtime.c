#include <stdio.h>
#include<stdlib.h>

struct tym
{
	int value;
	int isarrival;
};

int main()
{
    int t=0,count=0,max=0;
    scanf("%d",&t);
    struct tym arrival[t],deadline[t];
    int i=0,j=0,k=0;
    for(i=0;i<t;i++){
    	arrival[i].isarrival=1;
    	deadline[i].isarrival=0;
    }
    for(i=0;i<t;i++)
        scanf("%d %d",&arrival[i].value,&deadline[i].value);
    struct tym new[2*t],temp;
	for(i=0;i<t;i++)
	{
		new[k++]=arrival[i];
	}
	for(i=0;i<t;i++)
	{
		new[k++]=deadline[i];
	}
	//sort
	for(i=0;i<t;i++)
	{
		for(j=i+1;j<t;j++)
		{
			if(new[i].value == new[j].value && new[j].isarrival==1)
			{
				temp=new[i];
				new[i]=new[j];
				new[j]=temp;
			}	
			else if(new[i].value > new[j].value)
			{
				temp=new[i];
				new[i]=new[j];
				new[j]=temp;
			}
		}
	}
for(i=0;i<2*t;i++)
	printf("%d ",new[i].value);
    max=0;
    for(i=0;i<2*t;i++)
    {
    	if(new[i].isarrival==1)
    		count++;
    	else
    		count--;
    	if(count>max)
    		max=count;
    }
    //printf("%d\n",max-2);
    return 0;
}
