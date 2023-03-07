#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int stack[MAX];
int top;

void push()
{
	int data;
	if(top==MAX)
	{
		printf("\nStack overflow!!!\n");
	}
	else
	{
		printf("\nEnter value to push: ");
		scanf("%d",&data);
		top++;
		stack[top] = data;
		printf("\n%d has been inserted in STACK\n",data);
	}
}

void pop()
{
	int temp;
	if(top==-1)
	{
		printf("\nStack is EMPTY!!!\n");
		return;
	}
	else
	{
		temp = stack[top];
		top--;
		printf("\nPopped element is: %d",temp);
	}
}

void isempty()
{
	if(top==-1)
	{
		printf("\nSTACK is EMPTY!!!\n");
	}
	else
	{
		printf("\nSTACK is NOT Empty!!!\n");
	}
}

void isfull()
{
	if(top==MAX)
	{
		printf("\nSTACK is FULL!!!\n");
	}
	else
	{
		printf("\nSTACK is NOT FULL!!!\n");
	}
}

void display()
{
	int i;
	if(top==-1)
	{
		printf("\nStack Underflow!!!\n");
	}
	else
	{
		printf("\nStack:");
		for(i=top;i>-1;i--)
		{
			printf("\n |%d|",stack[i]);
			if(i==top)
			printf("Top");
		}
	}
}

void main()
{
	int choice;
	
	while(1)
	{
		printf("\n\n-----Menu-----\n\n");
		printf(" 1.Initialize\n");
		printf(" 2.Push\n");
		printf(" 3.Pop\n");
		printf(" 4.Isempty\n");
		printf(" 5.Iffull\n");
		printf(" 6.Display\n");
		printf(" 0.Exit\n");
	
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				top = -1;
				printf("\nStack has been Initialized!!!\n");
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
				isfull();
				break;
			case 6:
				display();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("\nAisa koi option nai hai!!!\n");
				break;
		}
	}

}



