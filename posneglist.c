#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node * insert(struct Node * head, int val)
{
	struct Node* NewNode;
	NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->data = val;
	NewNode->next = NULL;
		
	if(head == NULL)
	{
		head = NewNode;
	}
	else
	{
		struct Node *temp = head;
		while(temp->next != NULL)
		temp = temp->next;
		temp->next = NewNode;
	}

	return head;
}

void display(struct Node * head)
{
	int c = 0;
	struct Node*temp = head;
	
	while(temp != NULL)
	{
		printf("%d->",temp->data);
		temp = temp->next;
		c++;
	}
	printf("NULL");
	
	printf("\n Number of Nodes = %d \n",c);
}

void main()
{
	struct Node * positive=NULL, * negative = NULL;
	int i, n, numbers[77];
	
	printf("\nEnter how many numbers you want to insert: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\n Input Number %d: ",i+1);
		scanf("%d",&numbers[i]);
	}
	
	printf("\nGiven Numbers:\n");
	for(i=0;i<n;i++)
	{
		printf("%d",numbers[i]);
		if(i < n-1)
		{
			printf(",");
		}	
	}
	
	for(i=0;i<n;i++)
	{
		if(numbers[i] < 0)
		{
			negative = insert(negative, numbers[i]);
		}
		else
		{
			positive = insert(positive, numbers[i]);
		}
	}
	
	printf("\n\nPostive Numbers List: ");
	display(positive);
	
	printf("\nNegative Numbers List: ");
	display(negative);
}
