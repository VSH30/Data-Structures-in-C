#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node*left;
	struct node*right;
}stn;

void insert(stn * root, stn * node)
{
	if(root->data > node->data)
	{
		if(root->left==NULL)
			root->left=node;
		else
		{
			insert(root->left,node);
		}
	}
	if(root->data < node->data)
	{
		if(root->right==NULL)
			root->right=node;
		else
		{
			insert(root->right,node);
		}
	}
}

void preorder(stn * root)
{
	if(root!=NULL)
	{
		printf(" |%d| ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(stn * root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf(" |%d| ",root->data);
		inorder(root->right);
	}
}

void postorder(stn * root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf(" |%d| ",root->data);
	}
}

stn * search(stn*root,int val)
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
	int n,i,v;
	stn *root,*temp;
	root=NULL;
	printf("\nEnter number of elements: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter value of element %d: ",i+1);
		temp = (stn*)malloc(sizeof(stn));
		scanf("%d",&temp->data);
		temp->left=temp->right=NULL;
		
		if(root==NULL)
			root=temp;
		else
			insert(root,temp);
	}
	
	printf("\nPreorder: \n");
	preorder(root);	
	
	printf("\nInorder: \n");
	inorder(root);
	
	printf("\nPostorder: \n");
	postorder(root);
	
	printf("\nEnter value to search: ");
	scanf("%d",&v);
	
	temp=NULL;
	temp=search(root,v);
	
	if(temp!=NULL)
		printf("\n%d is found",temp->data);
	else
		printf("\nNot found!!!");
		
}
