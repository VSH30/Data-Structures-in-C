#include<iostream>
using namespace std;

int main()
{
	int i,a,b;
	
	for(i=1;i<=100;i++)
	{
		if(i%3==0 && i%5!=0)
		{
			printf(" Fizz ");
		}
		else if(i%3!=0 && i%5==0)
		{
			printf(" Buzz ");
		}
		else if(i%3==0 && i%5==0)
		{
			printf(" FizzBuzz ");
		}
		else
		{
			printf(" %d ",i);
		}
		
		if(i%10==0)
		{
			printf("\n");
		}
	}
	return 0;
}
