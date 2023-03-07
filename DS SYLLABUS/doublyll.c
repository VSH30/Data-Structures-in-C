#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *prev, *next;
} *head = NULL;

void create(int no)
{
	int i, val;
	
	for( i=0 ; i<no ; i++)
	{
		struct Node * NewNode;
		NewNode = (struct Node*)malloc(sizeof(struct Node));
		
		printf("\nEnter value of Node %d: ",i+1);
		scanf("%d",&val);
		
		NewNode->data = val;
		NewNode->next = NULL;
		
		if(head == NULL)
		{
			head = NewNode;
			NewNode->prev = NULL;
		}
		else
		{
			struct Node * temp;
			temp = head;
			
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = NewNode;
			NewNode->prev = temp;
		}
	}
	printf("\nDoubly linked list has been created!!!\n");
}

void disp()
{
	int tn = 0;
	if(head == NULL)
	{
		printf("\nDoubly Linked List is EMPTY!!!\n");
	}
	else
	{
		struct Node * temp;
		temp = head;
		
		printf("\nDoubly Linked List:");
		printf("\nNULL<=>(head)");
		while(temp != NULL)
		{
			tn++;
			printf("%d<=>",temp->data);
			temp = temp->next;
		}
		printf("NULL");
		printf("\n\n Number of Nodes = %d",tn);
	}
}

void main()
{
	int no, ch, mmm = 1;
	
	while(mmm==1)
	{
		printf("\n\n------MENU------\n\n");
		printf("1. Create\n");
		printf("2. Display\n");
		printf("0. EXIT\n");
		
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1:
				printf("\n\nEnter number of Nodes in Doubly Linked List: ");
				scanf("%d",&no);
				create(no);
				break;
			case 2:
				disp();
				break;
			case 0:
				mmm=0;
				break;
			default:
				printf("\n\nINVALIDDD!!\n\n");
				break;
		}
	}
	getch();
}
