//-------------VISHAL HANCHNOLI-------------//

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

//-------------VISHAL HANCHNOLI-------------//
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

//-------------VISHAL HANCHNOLI-------------//
//INSERT AT POSITION

void insatpos(int d[], int w)
{
	int i=0,p,m;
	printf("\n Enter the number to insert: ");
	scanf("%d",&m);
	printf("\n Enter the position: ");
	scanf("%d",&p);
	p=p-1;
	
	for(i=w;i>=p;i--)
	{
		d[i+1] = d[i];
	}
	d[p] = m;
	
	printf("\n %d inserted at %d position",m,p);
}

//-------------VISHAL HANCHNOLI-------------//
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

//-------------VISHAL HANCHNOLI-------------//
//LINEAR SEARCH

void linear(int t[], int y)
{
	int s,i;
	printf("\n Enter element to Search: ");
	scanf("%d",&s);
	
	for(i = 0;i < y;i++)
	{
		if(t[i] == s)
		{
			printf("%d element is present at %d position",s,i+1);
			break;
		}
	}
	if(i == y)
	{
		printf("\n\n Element %d is not present!!!",s);
	}
}

//-------------VISHAL HANCHNOLI-------------//
//BINARY SEARCH

void binary(int t[],int y)
{
	int f,m,l,s;
	
	printf("\n Enter element for search: ");
	scanf("%d",&s);
	
	f = 0;
	l = y-1;
	m = (f+l)/2;
	
	while(f <= l)
	{
		if(t[m] < s)
		{
			f = m + 1;
		}
		else if(t[m] == s)
		{
			printf("\n\n %d element is present at %d position \n",s,m+1);
			break;
		}
		else
		{
			l = m -1;
		}
		m = (f+l)/2;
	}
	if(f > l)
	{
		printf("\n %d is not present in the array\n",s);
	}
}

//-------------VISHAL HANCHNOLI-------------//
//BUBBLE SORT

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

//-------------VISHAL HANCHNOLI-------------//
//INSERTION SORT

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

//-------------VISHAL HANCHNOLI-------------//
//SELECTION SORT

void ssort(int a[],int n)
{
	int t,i,j,p;
	for (i = 0; i < (n - 1); i++)
	{
    	p = i;
   
		for (j = i + 1; j < n; j++)
    	{
    		if (a[p] > a[j])
    		{
    			p = j;
			}    
    	}
   		if (p != i)
    	{
			t = a[i];
			a[i] = a[p];
			a[p] = t;
    	}
	}
}

//-------------VISHAL HANCHNOLI-------------//
//MAIN

void main()
{
	int a[20],num,choice,choice2,choice3;
	
	printf("\n---------------------- VISHAL HANCHNOLI ----------------------\n");
	while(1)
	{
		printf("\n\n--Menu--\n\n");
		printf(" 1.Create ARRAY\n");
		printf(" 2.Display ARRAY\n");
		printf(" 3.Reverse ARRAY\n");
		printf(" 4.Insert at POSITION\n");
		printf(" 5.Delete from POSITION\n");
		printf(" 6.SEARCH (lINEAR or BINARY)\n");
		printf(" 7.SORT (BUBBLE,INSERTION and SELECTION)\n");
		printf(" 0.Exit\n");
		
		printf("\n Enter you choice: ");
		scanf("%d",&choice);
		printf("\n");
		
		switch(choice)
		{
			case 1:
				printf("\n Enter number of elements in the array:");
				scanf("%d",&num);
				create(a,num);
				break;
				
			case 2:
				display(a,num);
				break;
				
			case 3:
				rev(a,num);
				display(a,num);
				break;
			
			case 4:
				insatpos(a,num);
				num = num + 1;
				display(a,num);
				break;
			
			case 5:
				delfrompos(a,num);
				num = num - 1;
				display(a,num);
				break;
			
			case 6:
				printf("\n--Options--\n");
				printf(" 1.Linear Search\n 2.Binary Search\n");
				printf("\n Enter you choice: ");
				scanf("%d",&choice2);
				
				switch(choice2)
				{
					case 1:
						linear(a,num);
						break;
						
					case 2:
						binary(a,num);
						break;
							
					default:
						printf("\nInvalid input!!!\n");
						break;
				}
			break;
			
			case 7:
				printf("\n--Options--\n");
				printf(" 1.Bubble Sort\n 2.Insertion Sort\n 3.Selection Sort\n");
				printf("\n Enter you choice: ");
				scanf("%d",&choice3);
				
				switch(choice3)
				{
					case 1:
						bubblesort(a,num);
						display(a,num);
						break;
						
					case 2:
						insertionsort(a,num);
						display(a,num);
						break;
						
					case 3:
						ssort(a,num);
						display(a,num);
						break;
													
					default:
						printf("\nInvalid input!!!\n");
						break;
				}
			break;
				
			case 0:
				exit(1);
				break;
			
			default:
				printf("\nInvalid input\n");
		}
	}
}
