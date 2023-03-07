#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node * next;
};

struct Node * create(struct Node * head, int n)
{
	int i;
	
	for(i=0 ; i<n ; i++)
	{
		struct Node * NewNode = (struct Node*)malloc(sizeof(struct Node));
		printf("\nEnter Node %d value: ",(i+1));
		scanf("%d",&NewNode->data);
		NewNode->next = NULL;
		
		if(head == NULL)
		{
			head = NewNode;
		}
		else
		{
			struct Node * temp;
			temp = head;
			
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = NewNode;
		}
	}
	printf("\nLinked list has been Created!!!\n");
		
	return head;
}

void display(struct Node * head)
{
	if(head == NULL)
	{
		printf("NULL");
		return;
	}
	else
	{
		printf("%d=>",head->data);
	}
	display(head->next);
}

struct Node * insatend(struct Node * head, int value)
{
	struct Node * NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->data = value;
	NewNode->next = NULL;
	
	if(head == NULL)
	{
		head = NewNode;
	}else{
		struct Node * temp;
		temp = head;
		
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		
		temp->next = NewNode;
	}
	return head;
}

int check(struct Node * head, int value)
{
	while(head != NULL)
	{
		if(head->data == value)
			return 0;
		head = head->next;
	}
	return 1;
}

struct Node * Union(struct Node *a, struct Node *b, struct Node *c)
{
	while(a != NULL)
	{
		if(check(c,a->data))
			c = insatend(c,a->data);
		a = a->next;
	}
	while(b != NULL)
	{
		if(check(c,b->data))
			c = insatend(c,b->data);
		b = b->next;
	}
	return c;
}

void main()
{
	struct Node *ah, *bh, *ch, *temp;
	int ano, bno, cno;
	ah=NULL;
	bh=NULL;
	ch=NULL;
	
	printf("\nEnter number of Nodes in A: ");
	scanf("%d",&ano);
	ah = create(ah,ano);
	
	printf("\nEnter number of Nodes in B: ");
	scanf("%d",&bno);
	bh = create(bh,bno);
	
	ch = Union(ah,bh,ch);
	
	printf("\nList A:\n");
	display(ah);
	printf("\nList B:\n");
	display(bh);
	printf("\n\nUnion of A and B:\n");
	display(ch);
	
	printf("\n\n\n-------Even Odd List-------\n\n");
	ah=NULL;
	bh=NULL;
	ch=NULL;
	
	printf("\nEnter number of elements: ");
	scanf("%d",&cno);
	ch = create(ch,cno);
	printf("\nGiven List:\n");
	display(ch);
	
	temp = ch;
	while(temp != NULL)
	{
		if(temp->data % 2 == 0)
		{
			ah = insatend(ah,temp->data);
		}
		else
		{
			bh = insatend(bh,temp->data);
		}
		temp=temp->next;
	}
	printf("\n\nEven Numbers List:\n");
	display(ah);
	printf("\nOdd Numbers List:\n");
	display(bh);
}
