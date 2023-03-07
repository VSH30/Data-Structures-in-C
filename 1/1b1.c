#include<stdio.h>
#include<math.h>

void main()
{
	int a[20], b[20], c[20], x, i, d, d2, dd, ans=0;
	
	printf("Enter the degree of first Polynomial = ");
	scanf("%d",&d);
	
	for(i=0;i<=d;i++)
	{
		printf("Enter co-efficient of X^%d = ",i);
		scanf("%d",&a[i]);
	}
	
	printf("Enter the degree of Second Polynomial = ");
	scanf("%d",&d2);
	
	for(i=0;i<=d2;i++)
	{
		printf("Enter co-efficient of X^%d = ",i);
		scanf("%d",&b[i]);
	}
	
	if(d>d2)
	{
		dd = d;
		for(i=d2+1;i<=dd;i++)
		{
			b[i]=0;
		}
	}
	else if(d=d2)
	{
		dd = d;
	}
	else
	{
		dd = d2;
		for(i=(d+1);i<=dd;i++)
		{
			a[i]=0;
		}
	}
	
	printf("\nFirst Polynomial is = ");
	for(i=0;i<=d;i++)
	{
		printf("%dX^%d",a[i],i);
		if(i+1<=d)
		{
			printf(" + ");
		}
	}
	
	printf("\nSecond Polynomial is = ");
	for(i=0;i<=d2;i++)
	{
		printf("%dX^%d",b[i],i);
		if(i+1<=d2)
		{
			printf(" + ");
		}
	}
	
	printf("\nAddition of two polynomials = ");
	for(i=0;i<=dd;i++)
	{
		c[i] = a[i] + b[i];
	}
	
	for(i=0;i<=dd;i++)
	{
		printf("%dX^%d",c[i],i);
		if(i+1<=dd)
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
