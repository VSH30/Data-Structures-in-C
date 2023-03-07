#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
}*f=NULL,*r=NULL;

void enqueue()
{
	struct node * newnode=(struct node*)malloc(sizeof(struct node));
		
	printf("Enter node value: ");
	scanf("%d",&newnode->data);
	
	if(f==NULL && r==NULL)
	{
		f=r=newnode;
		r->next = f;
	}else{
		r->next = newnode;
		r = newnode;
		newnode->next = f;
	}
}

void dequeue()
{	
	if(f==NULL && r==NULL)
	{
		printf("\n Queue is EMPTY!!!\n");
	}else{
		struct node * t;
		t = f;
		
		if(f==r){
			f=r=NULL;
			free(t);
		}else{
			f=f->next;
			r->next=f;
			printf("\n Deleted element is %d",t->data);
			free(t);
		}	
	}
}

void display()
{
	if(f==NULL && r==NULL)
	{
		printf("\n Queue is EMPTY!!! \n");
		return;
	}else{
		struct node * temp;
		temp = f;
		printf("\n Queue is: \n");
		do{
			printf("|%d",temp->data);
			temp=temp->next;
		}while(temp!=f);
		printf("|");
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
