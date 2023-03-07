#include<stdio.h>
#include<stdlib.h>

int prec(char m)
{
	switch(m)
	{
		case '/':
		case '*':
			return 4;
		case '+':
		case '-':
			return 3;
		case '(':
			return 2;
	}
	return 0;
}

void evaluation(char post[20],int eee)
{
	char s;
	int i,value,j=-1,o1,o2,op,eval[20];
	
	for(i=0;post[i]!='\0';i++)
	{
		s = post[i];
		
		if(s=='+' || s=='-' || s=='/' || s=='*')
		{
			o2 = eval[j];
			j--;
			o1 = eval[j];
			j--;
			
			if(s=='+')
			{
				op = o1 + o2;
			}
			else if(s=='-')
			{
				op = o1 - o2;
			}
			else if(s=='*')
			{
				op = o1 * o2;
			}
			else if(s=='/')
			{
				op = o1 / o2;
			}
			j++;
			eval[j] = op; 
		}
		else
		{
			printf("Enter value of %s",s);
			scanf("%d",&value);
			j++;
			eval[j] = value;
		}
	}
	eee = eval[1];
}

void main()
{
	char postfix[20], stack[20], input[20], symbol;
	int i, j = 0, top = -1, value, ev;
	
	printf("Enter Infix Expression: ");
	scanf("%s",input);
	
	for(i=0;input[i]!='\0';i++)
	{
		symbol = input[i];
		
		if(symbol=='+' || symbol=='-' || symbol=='/' || symbol=='*')
		{
			while(prec(stack[top])>=prec(symbol))
			{
				postfix[j] = stack[top];
				j++;
				top--;
			}
			top++;
			stack[top] = symbol;
		}
		else if(symbol == ')')
		{
			while(stack[top]!='(')
			{
				postfix[j] = stack[top];
				j++;
				top--;
			}
			top--;
		}
		else if(symbol == '(')
		{
			top++;
			stack[top] = symbol;
		}
		else
		{
			postfix[j] = symbol;
			j++;
		}
	}
	
	while(top!=-1)
	{
		postfix[j] = stack[top];
		top--;
		j++;
	}
	
	postfix[j] = '\0';
	printf("\n Postfix expression is:\n %s \n",postfix);
	evaluation(postfix,ev);
	printf("%d",ev);
	getch();
}
