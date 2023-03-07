#include<stdio.h>

void main()
{
	int arr[20], n, i, find, replace, c=0;
	clrscr();
	printf("\nVSH\n");
	printf("Enter number of elements = ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter value of element %d = ",i+1);
		scanf("%d",&arr[i]);
	}
	
	printf("Given array is:");
	for(i=0;i<n;i++)
	{
		printf("%d,",arr[i]);	
	}
	
	printf("\nEnter element to find = ");
	scanf("%d",&find);
	
	printf("Enter element to replace %d = ",find);
	scanf("%d",&replace);
	
	for(i=0;i<n;i++)
	{
		if(find == arr[i])
		{
			arr[i] = replace;
		}
		else
		{
			c++;
		}
	}
	
	if(c == n)
	{
		printf("%d is not found in the array",find);
	}
	else
	{
		
		printf("Array after replacement:");
		for(i=0;i<n;i++)
		{
			printf("%d,",arr[i]);	
		}
	}

	getch();
}
