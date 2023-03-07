#include<stdio.h>
#include<math.h>

void main()
{
	int i,a,b;
	
	for(i=1;i<=100;i++)
	{
		if(i%3==0 && i%5==0)
		{
			printf(" FizzBuzz ");
		}
		else if(i%3==0)
		{
			printf(" Fizz ");
		}
		else if(i%5==0)
		{
			printf(" Buzz ");
		}
		else
		{
			printf(" %d ",i);
		}
		
		if(i%8 == 0)
		{
			printf("\n");
		}
	}
}
