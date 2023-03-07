#include<stdio.h>
#include<conio.h>
#include<math.h>

int evaluation(int [], int, int);

void main()
{
	int a[10],n,x,i,e;
	
	printf("\n---------------------- VISHAL HANCHNOLI ----------------------\n");
	printf("\n Enter the degree of Poynomial = ");
	scanf("%d",&n);
	printf("\n Enter the coefficient of Polynomial = ");
	for(i=n;i>=0;i--)
	{
		printf("\n co-efficient of A[%d]",i);
		scanf("%d",&a[i]);
	}
	
	printf("\n Entered Polynomial is: ");
	for(i=n;i>0;i--)
	{
		if(a[i]!=0)
		{
			printf("%dX^%d",a[i],i);
		}
	}
	printf("%d",a[i]);
	printf("\n\n Enter value of X: ");
	scanf("%d",&x);
	e = evaluation(a,n,x);
	printf("\n\n Evalutaion of Polynomial is = %d",e);
	getch();
}

int evaluation(int a[], int n, int x)
{
	int sum=0,i;
	for(i=n;i>=0;i--)
	{
		sum = sum + a[i]*pow(x,i);
	}
	return sum;
}
