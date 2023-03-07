#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
} *head = NULL;

//CREATE LL

void create(int n)
{
	int i,value;
	for(i = 0;i < n;i++)
	{
		struct Node *newNode;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter the value of node:");
		scanf("%d",&value);
		newNode->data = value;
		newNode->next = NULL;
		
		if(head == NULL)
		{
			head = newNode;
		}
		else
		{
			struct Node *temp = head;
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = newNode;
		}
	}
	printf("\n Linked list is created successfully \n");
}

//DISPLAY LL

void display()
{
	int c = 0;
	struct Node*temp = head;
	
	while(temp != NULL)
	{
		printf("%d->",temp->data);
		temp = temp->next;
		c++;
	}
	printf(" NULL");
	
	printf("\n Number of Nodes = %d",c);
}

//REVERSE LL

void rev()
{
	struct Node *t1,*t2,*t3;
	t1 = head;
	t2 = t1->next;
	t3 = t2->next;
	t1->next = NULL;
	
	while(t3)
	{
		t2->next = t1;
		t1 = t2;
		t2 = t3;
		t3 = t3->next;
	}
	
	t2->next = t1;
	head = t2;
}

//INSERT AT END

void insatend(int value)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		struct Node *temp = head;
		
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	printf("\n Node inserted at end \n\n");
}

//INSERT AT START

void insatst(int value)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	
	if(head == NULL)
	{
		newNode->next = NULL;
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	printf("\n Node is inserted at start \n\n");
}

//INSERT at POSITION

void insertatpos(int value, int p)
{
	int i = 0;
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	
	if(head == NULL)
	{
		newNode->next = NULL;
		head = newNode;
	}
	else
	{
		struct Node *temp = head;
		
		for(i = 0;i < (p-1);i++)
		{
			temp = temp->next;
		}
		
		newNode->next = temp->next;
		temp->next = newNode;
	}
	printf("\n Node inserted at %p position \n\n");
}

//MAIN

void main()
{
	int choice,value,n,key,c,a,p;
	
	while(1)
	{
		printf("\n\n--Menu--\n\n");
		printf(" 1.Create\n");
		printf(" 2.Display\n");
		printf(" 3.Reverse\n");
		printf(" 4.Insert at END\n");
		printf(" 5.Insert at START\n");
		printf(" 6. Insert at POSITION\n");
		printf(" 0.Exit\n");
		
		printf("\n Enter you choice: ");
		scanf("%d",&choice);
		printf("\n");
		
		switch(choice)
		{
			case 1:
				printf("\n Enter number of elements in the linked list:");
				scanf("%d",&n);
				create(n);
				break;
			
			case 2:
				display();
				break;
				
			case 3:
				rev();
				display();
				break;
			
			case 4:
				printf(" Enter the value to insert at end:");
				scanf("%d",&a);
				printf("\n");
				insatend(a);
				display();
				break;
			
			case 5:
				printf(" Enter the value to insert at start:");
				scanf("%d",&a);
				printf("\n");
				insatst(a);
				display();
				break;
			
			case 6:
				printf(" Enter the value to insert");
				scanf("%d",&a);
				printf(" Enter the position to insert at :");
				scabf("%d",&p);
				printf("\n");
				insatpos(a,p);
				display();
				break;
				
			case 0:
				exit(0);
				break;
			
			default:
				printf("Invalid input");
		}
	}
}
