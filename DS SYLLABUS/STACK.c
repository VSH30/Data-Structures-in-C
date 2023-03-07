#include<stdio.h>
#include<conio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push();
void pop();
void display();

void main()
{
	int choice,ss=1;
	char ch;

	printf("\n---------------------- VISHAL HANCHNOLI ----------------------\n");
	
	while(ss==1)
	{
		printf("\n 1.Push");
		printf("\n 2.Pop");
		printf("\n 3.Display");
		printf("\n 4.Exit");
		printf("\n Enter you choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				push();
				break;
			
			case 2:
				pop();
				break;
				
			case 3:
				display();
				break;
			
			case 4:
				ss = 2;
				break;
			
			default:
				printf("Invalid Input!!!");
				break;
		}
	}
	getch();
}

void push()
{
	int n;
	if(top == MAX - 1)
	{
		printf("\n Stack Overflow\n");
	}
	else
	{
		printf("\n Enter element in stack: ");
		scanf("%d",&n);
		top++;
		stack[top] = n;
	}
	printf("%d has been inserted in the STACK",n);
}

void pop()
{
	if(top == -1)
	{
		printf("\n Stack underflow\n");
	}
	else
	{
		printf("%d has been popped",stack[top]);
		top--;
	}
}

void display()
{
	int i;
	for(i=0;i!=-1;i--)
	{
		printf("\n%d\n",stack[i]);
	}
}
