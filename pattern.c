#include<stdio.h>
#include<conio.h>

void main()
{
	int i,j,n;
	
	printf("Enter number of rows: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n/2;j++)
		{
			printf("*");
		}
		printf("\n");
		if(i>=n/2)
		{
			for(j=1;j<=i;j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	getch();
}
