//-------------VISHAL HANCHNOLI-------------//
//Queue Using LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

//Structure of QUEUE (LinkedList)

struct node
{
	int data;
	struct node *link;
} *front, *rear;

//-------------VISHAL HANCHNOLI-------------//
//Create Queue ||Total nodes= n(Input from USER)||

void create(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		struct node *newnode;
		newnode = (struct node*)malloc(sizeof(struct node));

		printf("Enter value to be inserted \n");
		scanf("%d",&newnode->data);
		newnode->link = NULL;

		if(rear == NULL)
		{
			front = rear = newnode;
		}
		else
		{
			rear->link = newnode;
			rear = newnode;
		}
	}
	printf("Queue has been created");
}

//-------------VISHAL HANCHNOLI-------------//
//Display Function

void display()
{
	struct node *temp;
	int c=0;
	temp = front;

	if(front == NULL)
	{
		printf("Queue is Empty: \n");
	}
	else
	{
		printf("\n\nQueue = ");
	}
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->link;
		c++;
	}
}

//-------------VISHAL HANCHNOLI-------------//
//Insert Function (At END(REAR) as it is a QUEUE)

void insert()
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));

	printf("Enter value to be inserted \n");
	scanf("%d",&newnode->data);
	newnode->link = NULL;

	if(rear == NULL)
	{
		front = rear = newnode;
	}
	else
	{
		rear->link = newnode;
		rear = newnode;
	}

	printf("Element inserted at REAR.\n");
}

//-------------VISHAL HANCHNOLI-------------//
//Delete Function (From START(Front) as it a QUEUE)

void delet()
{
	struct node *temp;
	temp = front;

	if(front == NULL)
	{
		printf("Queue is Empty \n");
		front = rear = NULL;
	}
	else
	{
		printf("Deleted element is %d \n",front->data);
		front = front->link;
		free(temp);
	}
}

//-------------VISHAL HANCHNOLI-------------//
//Main Program/Function

void main()
{
	int choice, value, n;
	while(1)
	{
		printf("\n\n-----MENU-----\n\n");
		printf("1.Create\n");
		printf("2.Display Queue\n");
		printf("3.Insert (REAR)\n");
		printf("4.Delete (Front)\n");
		printf("5.Exit\n");

		printf("Enter choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter number of elements: ");
				scanf("%d",&n);
				create(n);
				display();
				break;

			case 2:
				display();
				break;

			case 3:
				insert();
				display();
				break;

			case 4:
				delet();
				display();
				break;

			case 5:
				exit(1);
				break;

			default:
				printf("INVALID OPTION!!! \n");
				break;
		}
	}
}
//-------------VISHAL HANCHNOLI-------------//

