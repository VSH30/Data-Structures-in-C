#include<stdio.h>
#include<conio.h>

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

void eval(char pf[25], int l)
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

void main()
{
	int j=-1,i;
	char postfix[25],exp[25];
	printf("\n Enter Postfix expression:\n");
	scanf("%s",exp);
	
	for(i=0;exp[i]!='\0';i++)
	{
		j++;
		postfix[j] = exp[i];
	}
	
	printf("%d",j);
	
	printf("\n\nEvaluation: \n\n");
	eval(postfix,j);
	
	getch();
}
