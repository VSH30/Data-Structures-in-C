#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 50

int top=-1;
char stack[MAX];
void push(char);
char pop();


void main()
{
	char str[50];
	int i;
	clrscr();

	printf("\n Enter the String = ");
	gets(str);
	printf("\n Original String = %s",str);

	for(i=0;i<strlen(str);i++)
	{
		push(str[i]);
	}
	for(i=0;i<strlen(str);i++)
	{
		str[i] = pop();
	}
	printf("\n Reversed String = %s",str);
	getch();
}

void push(char c)
{
	if(top==MAX-1)
	{
		printf("\n Stack Overflow");
	}
	else
	{
		stack[++top] = c;
	}
}

char pop()
{
	if(top == -1)
	{
		printf("Stack Underflow");
	}
	else
	{
		return stack[top--];
	}

}
