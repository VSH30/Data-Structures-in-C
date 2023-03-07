//-------------VISHAL HANCHNOLI-------------//

//INDEX:
//Main Function (21-81)
//Function precedence (86-98)
//Function eval (104-166)
//Function check (173-185)

//Infix to Postfix using STACK
#include<stdio.h>
#include<conio.h>

//User Defined Functions Declaration
int precedence(char x);    //Line 86
void eval(char pf[], int l);	//Line 104
int check(char pf[],char sym,int i);    //Line 173

//-------------VISHAL HANCHNOLI-------------//

//Main function(Original Program)
void main()
{
	char expr[25], postfix[25], stack[25], ch;
	int i, j = 0, top = -1;

	printf("\n\n-------------VISHAL HANCHNOLI-------------\n\n");

	printf("Enter a infix expression:\n");
	scanf("%s",expr);
	printf("\n\nEntered infix expression is : %s\n\n",expr);
	
	for(i = 0 ; expr[i] != '\0' ; i++)
	{
		ch = expr[i];

		if(ch == '*' || ch == '/' || ch == '+' || ch == '-')
		{ 
			while(precedence(ch) <= precedence(stack[top]))
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
			stack[top] = ch;
		}
		else if(ch == ')')
		{
			while(stack[top] != '(')
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
	while(top != -1)
	{
		postfix[j] = stack[top];
		j++;
		top--;
	}

	postfix[j] = '\0';
	printf("\n Postfix expression is:\n %s \n",postfix);
		
	printf("\n\nEvaluation: \n\n");
	eval(postfix,j);
	getch();
}

//-------------VISHAL HANCHNOLI-------------//

//Assign values according to precendece of scanned operator
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
	}
	return 0;
}

//-------------VISHAL HANCHNOLI-------------//

//Function for Evaluation of Postfix Expression

void eval(char pf[], int l)
{
	int m=-1, E[25], sym, val, op1, op2,i,x,ttt=-1,cal;
	char temp[ttt];
	
	for(i=0;i<l;i++)
	{
		sym = pf[i];
		
		if(sym == '*' || sym == '/' || sym == '+' || sym == '-')
		{
			op2 = E[m];
			m--;
			op1 = E[m];

			switch(sym)
			{
				case '+':
					cal = op1 + op2;
					break;
				case '-':
					cal = op1 - op2;
					break;
				case '*':
					cal = op1 * op2;
					break;
				case '/':
					cal = op1 / op2;
					break;
			}
			
			E[m] = cal;
			ttt++;
			temp[ttt] = sym;
		}
		else
		{
			//See the description of check function at the end of program
			x = check(pf,sym,i);

			if(x == 99)
			{
				printf("Enter value for %c: ",sym);
				scanf("%d",&val);

				m++;
				E[m] = val;
				ttt++;
				temp[ttt] = val;
			}
			else
			{
				val = temp[x];
				
				m++;
				E[m] = val;
				ttt++;
				temp[ttt] = val;
			}
		}
	}
	printf("Evaluation of Postfix %s is %d",pf,E[0]);
}

//-------------VISHAL HANCHNOLI-------------//

//Function to check if the character appears before in Postfix
//Eg-> A+B*A (here A appears twice so we just have to copy the value taken first time to all other A's)

int check(char pf[],char sym,int i)
{
	int tr;
	
	for(tr=0;tr<i;tr++)
	{	
		if(pf[tr] == sym)
		{
			return tr;
		}
	}
	return 99;
}

//-------------VISHAL HANCHNOLI-------------//
