#include<stdio.h>
#include<math.h>

void display(int arr[20], int degree)
{
	int i;
	for(i=0;i<=degree;i++)
	{
		printf("%dX^%d",arr[i],i);
		if(i+1<=degree)
		{
			printf(" + ");
		}
	}
}

void scan(int brr[20], int degree2)
{
	int i;
	for(i=0;i<=degree2;i++)
	{
		printf("Enter co-efficient of X^%d = ",i);
		scanf("%d",&brr[i]);
	}
}

void main()
{
	int a[20], b[20], c[20], x, i, d, d2, dd, ans=0;

	printf("Enter the degree of first Polynomial = ");
	scanf("%d",&d);
	scan(a,d);

	printf("Enter the degree of Second Polynomial = ");
	scanf("%d",&d2);
	scan(b,d2);

	if(d>d2)
	{
		dd = d;
		for(i=d2+1;i<=dd;i++)
		{
			b[i]=0;
		}
	}
	else if(d==d2)
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
	display(a,dd);
	
	printf("\nSecond Polynomial is = ");
	display(b,dd);

	for(i=0;i<=dd;i++)
	{
		c[i] = a[i] + b[i];
	}
	
	printf("\nAddition of two polynomials = ");
	display(c,dd);

	printf("\nEnter value of X = ");
	scanf("%d",&x);

	for(i=0;i<=dd;i++)
	{
		ans = ans + (c[i])*(pow(x,i));
	}

	printf("Solution of Given Polynomial = %d",ans);


}
