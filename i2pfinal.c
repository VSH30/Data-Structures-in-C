//-------------VISHAL HANCHNOLI-------------//

//INDEX:
//Main Function (Line 21 - 107)
//Function precedence (Line 111 - 123)
//Function eval (Line 128 - 226)
//Function check (Line 231 - 247)

//Infix to Postfix using STACK
#include<stdio.h>
#include<conio.h>

//User defined functions declaration
int precedence(char x); //Line 109
int check(char pf[],char sym,int i);  //Line 229
void eval(char pf[], int l); //Line 126

//-------------VISHAL HANCHNOLI-------------//

//Main function(Original Program)
void main()
{
	//Expression array, Postfix array, Stack array and ch(Element in expression)
	char expr[25], postfix[25], stack[25], ch;
	
	//i is for visitng each element in expression, j is for element number of Postfix and top is for stack as the stack is empty, so top=-1
	int i, j = 0, top = -1;

	printf("\n\n-------------VISHAL HANCHNOLI-------------\n\n");

	//Taking an Expression from user
	printf("Enter a infix expression:\n");
	scanf("%s",expr);
	printf("\n\nEntered infix expression is : %s\n\n",expr);
	
	//Selecting elements one by one from the Expression
	for(i = 0 ; expr[i] != '\0' ; i++)
	{

		//Element i = ch
		ch = expr[i];

		//If scanned element is an operator
		if(ch == '*' || ch == '/' || ch == '+' || ch == '-')
		{

			//Checking the Precedence
			//If (ch <= TOP) we shift the elements to Postfix one by one until it becomes false 
			while(precedence(ch) <= precedence(stack[top]))
			{
				postfix[j] = stack[top];
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
			stack[top] = ch;
		}

		//If scanned element is ')'
		else if(ch == ')')
		{
			//Shift all elements to Postfix till we get '(' to Postfix string
			while(stack[top] != '(')
			{
				postfix[j] = stack[top];
				top--;
				j++;
			}
			//Remove '('
			top--;
		}
		//Now all that's left is variables(alphabets) which we just add to postfix
		else
		{
			postfix[j] = ch;
			j++;
		}
	}
	
	//After all the elements are scanned,
	//Shift rest of the elements from stack to postfix until the stack is empty(i.e top = -1)
	while(top != -1)
	{
		postfix[j] = stack[top];
		j++;
		top--;
	}
	
	//End the Postfix string using '\0'
	postfix[j] = '\0';

	//Print the String and we are done!!!
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
	//m for top of Evaluation Stack (E), 
	//sym for visiting each character in Postfix, 
	//val to add Values to elements(Eg->A,B,C,etc)
	//op1 and op2 for Operands
	//x for marker(To get the index if repeated else get 'marker=99')
	//ttt for top of temp stack(Used to duplicate Postfix but with values in place of char)
	//cal to get the result of operation on op1 and op2
	
	int m=-1, E[25], sym, val, op1, op2,i,x,ttt=-1,cal;
	
	//Temp stack as mentioned above
	char temp[ttt];
	
	//Visiting all elements in Postfix Stack
	for(i=0;i<l;i++)
	{
		//Assign i th element to sym
		sym = pf[i];
		
		//If sym is and operator
		if(sym == '*' || sym == '/' || sym == '+' || sym == '-')
		{
			//Shift top element to op2
			op2 = E[m];
			m--;
			
			//Shift next element to op1
			op1 = E[m];
			
			//Converting char sym to operator
			//Doing required operations on op1 and op2
			//Getting the result of operation in cal
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
			
			//Adding the calculated value to top of Evaluation Stac
			E[m] = cal;
			
			//Copying the symbol as it is to Temp(Duplicated stack)
			ttt++;
			temp[ttt] = sym;
		}
		
		//Else the sym will be and char(A,B,C,etc) so we will Assign Value in place of that
		else
		{
			//Get the index if element repeated or else get marker in 'x'	
			x = check(pf,sym,i);
			
			//If we get market we take val from user
			if(x == 99)
			{
				//Getting value for sym from user
				printf("Enter value for %c: ",sym);
				scanf("%d",&val);
				//Adding value taken from user to Evaluation stack(E)
				m++;
				E[m] = val;
				
				//Adding value taken from user to Temp(Duplicated stack)
				ttt++;
				temp[ttt] = val;
			}
			
			//Else(means element is repeated and index is found and stored in x)
			else
			{
				//Now val = indexed value from Temp(duplicated stack)
				val = temp[x];
				
				//Adding value to Evaluation stack(E)
				m++;
				E[m] = val;
				
				//Adding value to Temp(Duplicated stack)
				ttt++;
				temp[ttt] = val;
			}
		}
	}
	//Now print the Evaluation
	//As the Evaluated value will be a single element present at 0 th index so print E[0]
	printf("Evaluation of Postfix %s is %d",pf,E[0]);
}

//-------------VISHAL HANCHNOLI-------------//
//Function to check if the character appears before in Postfix
//Eg-> A+B*A (here A appears twice so we just have to copy the value taken first time to all other A's)
int check(char pf[],char sym,int i)
{
	//tr for the index
	int tr;
	
	for(tr=0;tr<i;tr++)
	{	
		//If any char == sym
		if(pf[tr] == sym)
		{
			//return the index
			return tr;
		}
	}
	//Else return 99(Marker)
	return 99;
}

//-------------VISHAL HANCHNOLI-------------//
