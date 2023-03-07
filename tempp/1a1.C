#include<stdio.h>

void main()
{
	int arr[20], n, i, e, c=0;
	clrscr();
	printf("\nVSH\n");
	printf("Enter number of elements = ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter value of element %d = ",i+1);
		scanf("%d",&arr[i]);
	}

	printf("Enter element to find frequency = ");
	scanf("%d",&e);
	printf("Given array is:");
	for(i=0;i<n;i++)
	{
		printf("%d,",arr[i]);
		if(e == arr[i])
		{
			c++;
		}
	}

	printf("\n\n %d occured for %d times in given array",e,c);
	getch();
}
