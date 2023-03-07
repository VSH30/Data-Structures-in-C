#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*left;
	struct node*right;
}*root=NULL;

struct node* insert(struct node * r, struct node * nn)
{
	if(r == NULL)
		r = nn;
	else
	{
		if(r->data > nn->data)
			r->left = insert(r->left,nn);	
		else if(r->data < nn->data)
			r->right = insert(r->right,nn);
	}
	return r;
}

void preorder(struct node * r)
{
	if(r!=NULL)
	{
		printf(" |%d| ",r->data);
		preorder(r->left);
		preorder(r->right);
	}
}

void inorder(struct node * r)
{
	if(r!=NULL)
	{
		inorder(r->left);
		printf(" |%d| ",r->data);
		inorder(r->right);
	}
}

void postorder(struct node * r)
{
	if(r!=NULL)
	{
		postorder(r->left);
		postorder(r->right);
		printf(" |%d| ",r->data);
	}
}

struct node * search(struct node*root,int val)
{
	if(root==NULL)
		return NULL;
	if(root->data==val)
		return root;
	else{
		if(root->data>val)
			return(search(root->left,val));
		if(root->data<val)
			return(search(root->right,val));
	}	
}

void main()
{
	int num,a,j,v;
	printf("Enter number of elements: ");
	scanf("%d",&num);
	
	for(j=0;j<num;j++)
	{
		struct node * newnode;
		newnode = (struct node*)malloc(sizeof(struct node));
		
		printf("Enter value of node %d: ",j+1);
		scanf("%d",&newnode->data);
		newnode->left = NULL;
		newnode->right = NULL;
		
		root = insert(root,newnode);
	}
	
	printf("\nBST Created!!!\n");
	
	printf("\nPreoder: ");
	preorder(root);
	
	printf("\n\nInorder: ");
	inorder(root);
	
	printf("\n\nPostorder: ");
	postorder(root);
	
	printf("\nEnter value to search: ");
	scanf("%d",&v);
	
	if(search(root,v)!=NULL)
		printf("\n%d is found",v);
	else
		printf("\nNot found!!!");
	
	getch();
}
