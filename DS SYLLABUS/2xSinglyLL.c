#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node * create(struct Node * head, int n)
{
	int i,value;
	for(i = 0;i < n;i++)
	{
		struct Node* newNode;
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
	return head;
}

struct Node * insatend(struct Node * head,int value)
{
	struct Node* newNode;
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
			temp = temp->next;
		temp->next = newNode;
	}
	return head;
}

void display(struct Node * head)
{
	int c = 0;
	struct Node*temp = head;
	
	while(temp != NULL)
	{
		printf("%d->",temp->data);
		temp = temp->next;
		c++;
	}
	printf("NULL");
	
	printf("\n Number of Nodes = %d \n",c);
}

int check(struct Node * head, int x)
{
	struct Node * temp;
	temp = head;
	
	while(temp != NULL)
	{
		if(temp->data == x)
		{
			return 1;
		}
		temp = temp->next;
	}
	return 99;
}

struct Node * unionn(struct Node * a, struct Node * b, struct Node * c)
{
	struct Node *ta, *tb;
	int o;
	ta = a;
	tb = b;
	
	while(ta != NULL)
	{
		o = check(c, ta->data);
		if(o == 99)
		{
			c = insatend(c, ta->data);
		}
		ta = ta->next;
	}
	
	while(tb != NULL)
	{
		o = check(c, tb->data);
		if(o == 99)
		{
			c = insatend(c, tb->data);
		}
		tb = tb->next;
	}
	return c;
}

struct Node * connect(struct Node * a, struct Node * b)
{
	struct Node * ta,*tb;
	ta = a;
	tb = b;
	
	while(ta->next !=NULL)
	{
		ta = ta->next;
	}
	ta->next = tb;
	
	return a;
}

void main()
{
	int ch,ch1,n1,n2,i, n, numbers[77];;
	
	struct Node * h1;
	struct Node * h2;
	struct Node * h3;
	struct Node * positive, * negative;
	h1=NULL;
	h2=NULL;
	h3=NULL;
	positive=NULL;
	negative = NULL;
	while(1)
	{
		printf("\n\n-----Menu-----\n\n");
		printf("1-Create A and B\n");
		printf("2-Display A and B\n");
		printf("3-Union of A and B\n");
		printf("4-Postivie Negative List\n");
		printf("5-Concatinate A and B\n");
		printf("0-Exit\n");
		
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				h1 = NULL;
				h2 = NULL;
				printf("\nEnter number of nodes in A: ");
				scanf("%d",&n1);
				h1 = create(h1,n1);
				printf("\nEnter number of nodes in B: ");
				scanf("%d",&n2);
				h2 = create(h2,n2);
				
			case 2:
				printf("\nList A:\n");
				display(h1);
				printf("\nList B:\n");
				display(h2);
				break;
//case 3(union)			
			case 3:
				printf("\nList A:\n");
				display(h1);
				printf("\nList B:\n");
				display(h2);
				h3 = NULL;
				h3 = unionn(h1,h2,h3);
				display(h3);
				break;
//case 4(Pos Neg lists)				
			case 4:
				printf("\nEnter how many numbers you want to insert: ");
				scanf("%d",&n);
				negative = NULL;
				positive = NULL;
				for(i=0;i<n;i++)
				{
					printf("\n Input Number %d: ",i+1);
					scanf("%d",&numbers[i]);
				}
	
				printf("\nGiven Numbers:\n");
				for(i=0;i<n;i++)
				{
						printf("%d",numbers[i]);
						if(i < n-1)
						{
							printf(",");
						}	
				}
	
				for(i=0;i<n;i++)
				{
					if(numbers[i] < 0)
					{
						negative = insatend(negative, numbers[i]);
					}
					else
					{
						positive = insatend(positive, numbers[i]);
					}
				}
	
				printf("\n\nPostive Numbers List: ");
				display(positive);
	
				printf("\nNegative Numbers List: ");
				display(negative);
				break;
//case 5(concatinate)
			case 5:
				printf("\nList A:\n");
				display(h1);
				printf("\nList B:\n");
				display(h2);
				h3 = NULL;
				h3 = connect(h1,h2);
				printf("\nConcatinated List:\n");
				display(h3);
				break;
				
			case 0:
				exit(0);
				break;
				
			default:
				printf("\nINVALID!!!\n");
				break;	
		}
	}
}
