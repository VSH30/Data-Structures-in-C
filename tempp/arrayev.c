#include<stdio.h>
#include<conio.h>

void main()
{
	int n;
	printf("\n Enter number of elements:\n");
	scanf("%d",&n);
	
	int a[n],i,j,t,d;
	
	printf("\n Enter %d elements:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	if(n%2==0)
	{
		d = n/2;
	}
	else
	{
		d = (n+1)/2;
	}
	
	for(i=0;j=n-1;i<d,i++,j--)
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	
	printf("\n Reversed array is:\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d \n",a[i]);
	}
	
	getch();
}
