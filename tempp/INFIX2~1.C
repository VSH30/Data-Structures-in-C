//Infix to Postfix using STACK
#include<stdio.h>
#include<conio.h>

//Assign values according to precendece of scanned operator
int scanned(char x)
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

//Assign values according to precendece of the Element at TOP of STACK
int topelement(char x)
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

//Re

//Main function(Original Program)
void main()
{
	char expr[15], p[15], stack[15], ch;
	int i, j=0, top=-1;

	//Taking an Expression from user
	printf("Enter a infix expression:\n");
	scanf("%s",expr);

	//Adding a marker '~' to Stack
	top++;
	stack[top] = '~';

	//Selecting elements one by one from the Expression
	for(i=0; expr[i]!='\0';i++)
	{

		//Element i = ch
		ch = expr[i];

	//If scanned element is an operator
		if(ch=='*'||ch=='/'||ch=='+'||ch=='-')
		{

			//Checking the Precedence
			//If (ch <= TOP) we shift the elements to Postfix one by one until it becomes false 
			while(scanned(ch)<=topelement(stack[top]))
			{
				p[j] = stack[top];
				top--;
				j++;
			}

			//Now add the Scanned element to stack
			top++;
			stack[top] = ch;
		}
		

		//If scanned element is '(' just add it to stack
		else if(ch == '(')
		{
			top++;
			stack[top]=ch;
		}

		//If scanned element is ')'
		else if(ch == ')')
		{

			//Shift all elements to Postfix till we get '(' to Postfix string
			while(stack[top]!='(')
			{
				p[j] = stack[top];
				top--;
				j++;
			}

			//Remove '('
			top--;
		}

		//Now all that's left is variables(alphabets) which we just add to postfix
		else
		{
			p[j] = ch;
			j++;
		}
	}
	
	//After all the elements are scanned,
	//Shift rest of the elements from stack to postfix until we get the marker '~'
	while(stack[top]!='~')
	{
		p[j]=stack[top];
		j++;
		top--;
	}
	
	//End the Postfix string using '\0'
	p[j] = '\0';

	//Print the String and we are done!!!
	printf("\n Postfix expression is:\n %s \n",p);
		
	getch();
}
