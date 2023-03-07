#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
} *head = NULL;

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

void createfromnumber(int number)
{
	int value;
	while(number != 0)
	{
		value = number%10;
		//code of insatst
		struct Node *newNode;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = value;
		
		if(head == NULL)
		{
			newNode->next = NULL;
			head = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
			number = number/10;
	}
	printf("\n Linked list is created successfully \n");
}

void main(){
	int number;
printf("\nEnter a number(to create LL using its digits): ");
				scanf("%d",&number);
				createfromnumber(number);
				printf("\nCreated Linked List:\n");
				display();
}
