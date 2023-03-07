#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node * next;
} *top;

void push()
{
	struct Node * NewNode;
	NewNode=(struct Node*)malloc(sizeof(struct Node));
	printf("\nEnter Element to Push: ");
	scanf("%d",&NewNode->data);
	
	if(top==NULL)
	{
		top=NewNode;
		NewNode->next = NULL;
	}
	else
	{
		NewNode->next = top;
		top = NewNode;
	}
	printf("\n%d has been pushed!!!\n",NewNode->data);
}

void pop()
{
	if(top==NULL)
	{
		printf("\nStack Underflow!!!\n");
	}
	else
	{
		struct Node * temp = top;
		top = top->next;
		printf("\nPopped Element if %d",temp->data);
		free(temp);
	}
}

void isempty()
{
	if(top == NULL)
	{
		printf("\nStack is EMPTY!!!\n");
	}
	else
	{
		printf("\nStack is NOT EMPTY!!!\n");
	}
}

void display()
{
	if(top == NULL)
	{
		printf("\nStack Underflow!!!\n");
	}
	else
	{
		struct Node * temp;
		temp = top;
		
		printf("\nStack:");
		while(temp != NULL)
		{
			printf("\n|%d|",temp->data);
			if(temp==top)
				printf("(TOP)");
			temp = temp->next;
		}
	}
}

void main()
{
	int ch;
	
	while(1)
	{
		printf(" 1.Initialize\n");
		printf(" 2.Push\n");
		printf(" 3.Pop\n");
		printf(" 4.Isempty\n");
		printf(" 5.Display\n");
		printf(" 0.Exit\n");
		
		printf("Enter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				top=NULL;
				printf("\nStack has been initialized!!!\n");
				break;
			case 2:
				push();
				break;
			case 3:
				pop();
				break;
			case 4:
				isempty();
				break;
			case 5:
				display();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("\nAisa koi option nahi hai!!!\n");
				break;
		}
	}
}
