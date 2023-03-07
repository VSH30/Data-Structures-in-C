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

void bubblesort(int p[],int q)
{
	int i,j,t;
	for (i=0;i<q-1;i++)
	{
    	for (j=0;j<q-i-1;j++)
		{ 
    		if (p[j] > p[j+1])
			{ 
        		t = p[j];
        		p[j] = p[j+1];
        		p[j+1] = t;
        	}
        }
	}
	printf("\n Bubble sort done successfully!!!\n");
}


void main()
{
	int a[20],num;
	printf("\n Enter number of elements in the array:");
	scanf("%d",&num);
	create(a,num);
	display(a,num);
	bubblesort(a,num);
	display(a,num);
}
