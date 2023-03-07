#include<stdio.h>

void main()
{
	int arr[20], n, i, brr[20];
	clrscr();
	printf("\nVSH\n");
	printf("Enter number of elements = ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter value of element %d = ",i+1);
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<n;i++)
	{
		brr[i] = arr[i];
	}
	
	printf("Given array is:");
	for(i=0;i<n;i++)
	{
		printf("%d,",arr[i]);	
	}
	
	printf("\nCopy of given array is:");
	for(i=0;i<n;i++)
	{
		printf("%d,",brr[i]);	
	}
	getch();
}
