#include<stdio.h>
#include<math.h>

void main()
{
	int a[20], b[20], x, i, d, ans=0;
	clrscr();
	printf("\nVSH\n");
	printf("Enter the degree of Polynomial = ");
	scanf("%d",&d);
	
	for(i=0;i<=d;i++)
	{
		printf("Enter co-efficient of X^%d = ",i);
		scanf("%d",&a[i]);
	}
	
	printf("Given Polynomial is = ");
	for(i=0;i<=d;i++)
	{
		printf("%dX^%d",a[i],i);
		if(i+1<=d)
		{
			printf(" + ");
		}
	}
	
	printf("\nEnter value of X = ");
	scanf("%d",&x);
	
	for(i=0;i<=d;i++)
	{
		ans = ans + (a[i])*(pow(x,i));
	}
	
	printf("Solution of Given Polynomial = %d",ans);
	
	getch();
	
}
