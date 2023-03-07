#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
} *head = NULL;

//-------------VISHAL HANCHNOLI-------------//
//CREATE LL

void create(int n)
{
	int i,value;
	for(i = 0;i < n;i++)
	{
		struct Node* newNode;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter the value of node:");
		scanf("%d",&value);
		newNode->data = value;
		newNode->next = NULL;
		
		if(head == NULL)
		{
			head = newNode;
		}
		else
		{
			struct Node *temp = head;
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = newNode;
		}
	}
	printf("\n Linked list is created successfully \n");
	display();
}

//-------------VISHAL HANCHNOLI-------------//
//DISPLAY LL

void display()
{
	int c = 0;
	struct Node*temp = head;
	
	printf("\nLinked List:\n");
	while(temp != NULL)
	{
		printf("%d->",temp->data);
		temp = temp->next;
		c++;
	}
	printf("NULL");
	
	printf("\n Number of Nodes = %d\n",c);
}

void main()
{
	int n;
	printf("Enter number of nodes : ");
	scanf("%d",&n);
	create(n);
	
}
