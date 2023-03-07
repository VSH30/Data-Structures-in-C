#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node * next;
} *head = NULL;

void create(int n)
{
	int i, val;
	for( i = 0 ; i < n ; i++ )
	{
		struct Node * NewNode;
		NewNode = (struct Node*)malloc(sizeof(struct Node));
		
		printf("\nEnter value of Node %d: ",i+1);
		scanf("%d",&val);
		
		NewNode->data = val;
		
		if(head == NULL)
		{
			head = NewNode;
			NewNode->next = head;
		}
		else
		{
			struct Node * temp;
			temp = head;
			
			while(temp->next != head)
			{
				temp = temp->next;
			}
			temp->next = NewNode;
			NewNode->next = head;
		}
	}
	printf("\n\nCircular Linked List has been created!!!\n\n");
}

void disp()
{
	int tn = 0;
	if(head == NULL)
	{
		printf("\n\nCircular Linked List is EMPTY!!!\n\n");
	}
	else
	{
		struct Node * temp;
		temp = head;

		do
		{
			printf("%d=>",temp->data);
			tn++;
			temp = temp->next;
		}
		while(temp != head);
		printf("(head)%d",head->data);
		printf("\n\nTotal Nodes = %d",tn);
	}
}

void main()
{
	int n;
	
	printf("Enter Number of Nodes in Circular Linked List: ");
	scanf("%d",&n);
	
	create(n);
	disp();
}
