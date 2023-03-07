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
	int l = 0;
	printf("\nArray is: ");
	for(l = 0;l<q;l++)
	{
		printf("%d ",b[l]);
	}
}

//INSERT AT POSITION

void insatpos(int d[], int w)
{
	int j=0,p,m;
	printf("\n Enter the number to insert: ");
	scanf("%d",&m);
	printf("\n Enter the position: ");
	scanf("%d",&p);
	p=p-1;

	for(j=w;j>=p;j--)
	{
		d[j+1] = d[j];
	}
	d[p] = m;

	printf("\n %d inserted at %d position",m,p);
}

//REVERSE ARRAY

void rev(int e[], int x)
{
	int i,j,t,u;
	if((x%2) == 0)
	{
		u = x/2;
	}
	else
	{
		u = (x+1)/2;
	}

	for(i=0,j=(x-1);i<u;i++,j--)
	{
		t = e[i];
		e[i] = e[j];
		e[j] = t;
	}
}

//DELETE FROM POSITION

void delfrompos(int g[], int h)
{
	int pos,i;
	printf("\n Enter the position of element to delete: ");
	scanf("%d",&pos);
	pos = pos-1;

	for(i = pos; i<(h-1);i++)
	{
		g[i] = g[i+1];
	}
}

//MAIN

void main()
{
	int a[20],num,choice;

	while(1)
	{
		printf("\n\n--Menu--\n\n");
		printf(" 1.Create\n");
		printf(" 2.Display\n");
		printf(" 3.Reverse\n");
		printf(" 4.Insert at POSITION\n");
		printf(" 5.Delete from POSITION\n");
		printf(" 0.Exit\n");

		printf("\n Enter you choice: ");
		scanf("%d",&choice);
		printf("\n");

		switch(choice)
		{
			case 1:
				printf("\n Enter number of elements in the array:");
				scanf("%d",&num);
				create(a[20],num);
				break;

			case 2:
				display(a[20],num);
				break;

			case 3:
				rev(a[20],num);
				display(a[20],num);
				break;
			
			case 4:
				insatpos(a[20],num);
				num = num + 1;
				display(a[20],num);
				break;
			
			case 5:
				delfrompos(a[20],num);
				num = num - 1;
				display(a[20],num);
				break;
			
			case 0:
				exit(1);
				break;
			
			default:
				printf("Invalid input");
		}
	}
}
