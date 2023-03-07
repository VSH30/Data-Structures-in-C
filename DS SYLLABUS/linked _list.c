//-------------VISHAL HANCHNOLI-------------//

//---------------Linked List---------------//

//[LINE No]INDEX(Menu number if present)

//[28] Structure of Linked List
//[40] Create (1)
//[70] Display (2)
//[90] Reverse (3)
//[113] Insert at END (4)
//[140] Insert at START (5)
//[162] Insert at POSITION (6)
//[192] Delete from END (7)
//[221] Delete from START (8)
//[245] Delete from POSITION (9)
//[284] Search an Element (10)
//[305] Sort Linked List (11)
//[333] Count Non-Zero,Even and Odd (12)
//[371] Swap nth and mth element (13)
//[397] Display alternate NODES (14)
//[420] Remove LAST + Add at FIRST (15)
//[441] Create a List from DIGITS of Number (16)
//[470-644] MAIN function||IMPORTANT||

//----------------Thank You-----------------//

//-------------VISHAL HANCHNOLI-------------//
//Structure of LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
} *head = NULL;

//-------------VISHAL HANCHNOLI-------------//
//CREATE LL

void create(int n)
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
}

//-------------VISHAL HANCHNOLI-------------//
//DISPLAY LL

void display()
{
	int c = 0;
	struct Node*temp = head;
	
	printf("\nLinked List:\n");
	while(temp != NULL)
	{
		printf("%d->",temp->data);
		temp = temp->next;
		c++;
	}
	printf("NULL");
	
	printf("\n Number of Nodes = %d\n",c);
}

//-------------VISHAL HANCHNOLI-------------//
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

//-------------VISHAL HANCHNOLI-------------//
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

//-------------VISHAL HANCHNOLI-------------//
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

//-------------VISHAL HANCHNOLI-------------//
//INSERT at POSITION

void insatpos(int value, int p)
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
	printf("\n Node inserted at %d position \n\n",p);
}

//-------------VISHAL HANCHNOLI-------------//
//Delete from END

void delend()
{
   if(head == NULL)
   {
      printf("\nList is Empty\n");
   }
   else
   {
      struct Node *temp1 = head,*temp2;
      if(head->next == NULL)
         head = NULL;
      else
      {
         while(temp1->next != NULL)
         {
             temp2 = temp1;
             temp1 = temp1->next;
         }
         temp2->next = NULL;
      }
      free(temp1);
      
      printf("\nNode deleted from end\n\n");
   }
}

//-------------VISHAL HANCHNOLI-------------//
//Delete from START

void delstrt()
{
   if(head == NULL)
  printf("\n\nList is Empty");
   else
   {
      struct Node *temp = head;
      if(head->next == NULL)
      {
        head = NULL;
        free(temp);
      }
      else
      {
         head = temp->next;
         free(temp);
         printf("\nNode deleted from start\n\n");
      }
   }
}

//-------------VISHAL HANCHNOLI-------------//
//Delete from POSITION
void delpos(int p)
{
	int i=1;
	struct Node *t1, *t2;
		t1 = head;
		t2 = t1->next;
	
	if(head == NULL)
	{
		printf("\nLinked list is Empty!!!\n");
	}
	else if(p == 1)
	{
		head = t2;
		free(t1);
		printf("\nNode at 1st Position deleted!!!\n");
	}
	else
	{	
		while(i<p-1)
		{
			t1 = t2;
			t2 = t2->next;
			i++;
			if(t2->next == NULL)
			{
				printf("\nPosition is greater than the number of Nodes!!!\n");
				return;
			}
		}
		t1->next = t2->next;
		printf("\nNode at %d Position(value = %d) deleted!!!\n",p,t2->data);
		
		free(t2);
	}
}

//-------------VISHAL HANCHNOLI-------------//
//Search an ELEMENT

void search(int x)
{
	struct Node*temp;
	int posi=1; 
	temp = head;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            printf("Element %d is present at %d position\n",x,posi);
            return;
        }
        posi++;
        temp = temp->next;
	}
	printf("Element %d is not present in the LIST\n",x);
}

//-------------VISHAL HANCHNOLI-------------//
//Sort LL

void sortll()
{
	struct Node *temp, *startpos;
	int tempdata;
	startpos = head;
	
	while(startpos != NULL)
	{
		temp = startpos->next;
		
		while(temp != NULL)
		{
			if(startpos->data > temp->data)
			{
				tempdata = startpos->data;
				startpos->data = temp->data;
				temp->data = tempdata;
			}
			temp = temp->next;
		}
		startpos = startpos->next;
	}
	printf("\nLinkedList has been sorted!!!\n");
}

//-------------VISHAL HANCHNOLI-------------//
//Count Non-Zero Even Odd

void nzevod()
{
	struct Node * temp;
	int nonz=0, even=0, odd=0;
	
	temp = head;
	if(head == NULL)
	{
		printf("\nList is EMPTY!!!\n");
	}
	else
	{
		while(temp != NULL)
		{
			if(temp->data != 0)
			{
				nonz++;
			}
			
			if(temp->data % 2 == 0)
			{
				even++;
			}
			else
			{
				odd++;
			}
			temp = temp->next;
		}
	}
	printf("\nNumber of NonZero: %d",nonz);
	printf("\nNumber of Even: %d",even);
	printf("\nNumber of Odd: %d",odd);
}

//-------------VISHAL HANCHNOLI-------------//
//Swap nth and mth element

void swap(int mm, int nn)
{
	struct Node * tempM,*tempN;
	int var,i;
	tempM = head;
	tempN = head;
	
	for(i=1;i<mm;i++)
	{
		tempM = tempM->next;
	}
	for(i=1;i<nn;i++)
	{
		tempN = tempN->next;
	}
	
	var = tempM->data;
	tempM->data = tempN->data;
	tempN->data = var;
	
	printf("\nElement at %d pos has been swapped with %d pos\n",nn,mm);
}

//-------------VISHAL HANCHNOLI-------------//
//Display alternate Nodes(from start)

void displayalt()
{
	int c = 0;
	struct Node*temp = head;
	
	printf("\nAlt nodes in Linked List(from start):\n");
	while(temp != NULL)
	{
		printf("%d",temp->data);
		if(temp->next == NULL)
		{
			return;
		}
		printf("->");
		temp = temp->next->next;
	}
	printf("NULL");

}

//-------------VISHAL HANCHNOLI-------------//
//Remove last and inst at start

void last2first()
{
	struct Node *t1, *t2;
	t1 = head;
	t2 = t1->next;
	
	while(t2->next != NULL)
	{
		t1 = t2;
		t2 = t2->next;
	}
	t1->next = NULL;
	t2->next = head;
	head = t2;
	
	printf("\nLAST Node inserted has been inserted at START\n");
}

//-------------VISHAL HANCHNOLI-------------//
//Create LL using digits of a given number

void createfromnumber(int number)
{
	int value;
	while(number != 0)
	{
		value = number%10;
		//code of insatst
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
			number = number/10;
	}
	printf("\n Linked list is created successfully \n");
}

//-------------VISHAL HANCHNOLI-------------//
//MAIN

void main()
{
	int choice,value,n,key,c,a,p,nth,mth,number;

	while(1)
	{
		printf("\n-----VISHAL HANCHNOLI-----\n");
		printf("\n\n--Menu--\n\n");
		
		printf(" 1.Create\n");
		printf(" 2.Display\n");
		printf(" 3.Reverse\n");
		printf(" 4.Insert at END\n");
		printf(" 5.Insert at START\n");
		printf(" 6.Insert at POSITION\n");
		printf(" 7.Delete from END\n");
		printf(" 8.Delete from START\n");
		printf(" 9.Delete from POSITION\n");
		printf(" 10.SEARCH\n");
		printf(" 11.SORT(Ascending)\n");
		printf(" 12.SORT(Descending)\n");
		printf(" 13.Count Non-Zero, Even and Odd\n");
		printf(" 14.Swap nth and mth\n");
		printf(" 15.Display Alternate Nodes\n");
		printf(" 16.Remove Last and Insert at START\n");
		printf(" 17.Create Linklist with a NUMBER\n");
		printf(" 99.Empty List(Delete all NODES)\n");
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
				printf("\nORIGINAL:");
				display();
				rev();
				printf("\nAFTER REVERSE:");
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
				scanf("%d",&p);
				printf("\n");
				insatpos(a,p);
				display();
				break;
			
			case 7:
				delend();
				display();
				break;
				
			case 8:
				delstrt();
				display();
				break;
					
			case 9:
				printf("Enter position to delete an element : ");
				scanf("%d",&p);
				delpos(p);
				display();
				break;
				
			case 10:
				printf(" Enter the value to SEARCH:");
				scanf("%d",&a);
				printf("\n");
				search(a);
				break;
				
			case 11:
				sortll();
				display();
				break;
			
			case 12:
				sortll();
				rev();
				display();
				break;
			
			case 13:
				display();
				nzevod();
				break;
			
			case 14:
				printf("Enter nth pos: ");
				scanf("%d",&nth);
				printf("\nEnter mth pos: ");
				scanf("%d",&mth);
				
				if(mth>0 && nth>0 && mth<=n && nth<=n && mth!=nth)
				{
					swap(nth,mth);
					display();	
				}
				else
				{
					printf("\nCANT SWAP(Positions INVALID)!!!\n");
				}
				break;
				
			case 15:
				display();
				displayalt();
				break;
			
			case 16:
				printf("\nBefore switching:\n");
				display();
				last2first();
				printf("\nAfter switching:\n");
				display();	
				break;
			
			case 17:
				printf("\nEnter a number(to create LL using its digits): ");
				scanf("%d",&number);
				createfromnumber(number);
				printf("\nCreated Linked List:\n");
				display();
				break;
				
			case 99:
				head = NULL;
				printf("\nLinked List has been EMPTIED!!!\n");
				break;
			case 0:
				exit(0);
				break;
			
			default:
				printf("Invalid input");
		}
	}
}

//-------------VISHAL HANCHNOLI-------------//
