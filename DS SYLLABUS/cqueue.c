#include<stdio.h>
#include<stdlib.h>

#define size 5

int items[size];
int f=-1, r=-1;

int isfull()
{
	if((f==r+1) || (f==0 && r==size-1))return 1;
	return 0;
}

int isempty()
{
	if(f==-1)return 1;
	return 0;
}

void enqueue()
{
	int val;
	if(isfull())
	{
		printf("\n Queue is FULL!!!\n");
		return;
	}else{
		if(f==-1)f=0;
		r = (r+1)%size;
		printf("\n Enter value: ");
		scanf("%d",&items[r]);
		printf("\n %d inserted in the Queue \n",items[r]);
	}
}

void dequeue()
{
	int temp;
	if(isempty())
	{
		printf("\n Queue is EMPTY!!!\n");
	}else{
		temp = items[f];
		if(f==r)f=r=-1;
		else
		f = (f+1)%size;
		
		printf("Deleted element is %d",temp);
	}
}

void display()
{
	int i;
	if(isempty())
	{
		printf("\n Queue is EMPTY!!! \n");
		return;
	}else{
		printf("\n Queue is: \n");
		printf("Front = %d",f);
		printf("\n Items: \n");
		
		for(i=f;i!=r;i=(i+1)%size)
		{
			printf("|%d",items[i]);
		}
		printf("|%d|",items[r]);
		printf("\n Rear = %d",r);
	}
}

void main()
{
	int c;
	while(1)
	{
		printf("\n\n-----MENU-----\n\n");
		printf("1. EnQueue(Insert)\n");
		printf("2. DeQueue(Delete)\n");
		printf("3. Display Queue\n");
		printf("0. Exit\n");
		
		printf("\nEnter choice: ");
		scanf("%d",&c);
		
		switch(c)
		{
			case 1:enqueue();break;
			case 2:dequeue();break;
			case 3:display();break;
			case 0:exit(0);break;
			default:printf("\nINVALID OPTION!!!!\n");
		}
	}
}
