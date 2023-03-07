#include<stdio.h>
#include<conio.h>

//CREATE ARRAY

void create(int v[], int num)
{
	int i=0;
	for(i = 0;i<num;i++)
	{
		printf("\n Enter element %d:",i+1);
		scanf("%d",&v[i]);
	}
	printf("\n\n Array is created \n\n");
}

//DISPLAY ARRAY

void display(int b[], int q)
{
	int i = 0;
	printf("\n Array is: ");
	for(i = 0;i<q;i++)
	{
		printf("%d ",b[i]);
	}
}

void insertionsort(int a[],int n)
{
	int x,y,k;
	for(x=1;x<n;x++)
	{
		k=a[x];
		for(y=x-1;y>=0&&k<a[y];y--)
		{
			a[y+1]=a[y];
		}
		a[y+1]=k;
	}
	printf("\n Insertion sort done successfully!!!\n");
}

void main()
{
	int num,arr[20];
	printf("Enter number of elements: ");
	scanf("%d",&num);
	create(arr,num);
	display(arr,num);
	insertionsort(arr,num);
	display(arr,num);
}
