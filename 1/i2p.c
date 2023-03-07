//Infix to Postfix using STACK
#include<stdio.h>
#include<conio.h>

//VSH

int precedence(char x)
{
	switch(x)
	{
		case '*':
		case '/':
			return 4;
		case '+':
		case '-':
			return 3;
		case '(':
			return 2;
		case '~':
			return 1;
	}
	return 0;
}

void main()
{
	char expr[15], postfix[15], stack[15], ch;
	int i, j=0, top=-1;

	printf("Enter a infix expression:\n");
	scanf("%s",expr);
	
	top++;
	stack[top] = '~';

	for(i=0; expr[i]!='\0';i++)
	{
		ch = expr[i];
		if(ch=='*'||ch=='/'||ch=='+'||ch=='-')
		{
			while(precedence(ch)<=precedence(stack[top]))
			{
				postfix[j] = stack[top];
				top--;
				j++;
			}
			top++;
			stack[top] = ch;
		}
		else if(ch == '(')
		{
			top++;
			stack[top]=ch;
		}
		else if(ch == ')')
		{
			while(stack[top]!='(')
			{
				postfix[j] = stack[top];
				top--;
				j++;
			}
			top--;
		}
		else
		{
			postfix[j] = ch;
			j++;
		}
	}
	
	while(stack[top]!='~')
	{
		postfix[j]=stack[top];
		j++;
		top--;
	}
	
	postfix[j] = '\0';
	printf("\n Postfix expression is:\n %s \n",postfix);
	getch();
}	
