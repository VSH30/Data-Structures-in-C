#include<stdio.h>
#include<stdlib.h>

struct Ghar
{
	int Logg;
	struct Ghar * agla;
} *PehlaGhar = NULL;

void create(n)
{
	int i,logg;
	for(i=0;i<n;i++)
	{
		struct Ghar * NayaGhar;
		NayaGhar = (struct Ghar*)malloc(sizeof(struct Ghar));
		printf("Ghar(%d) mai kitne log chahiye: ",i+1);
		scanf("%d",&logg);
		NayaGhar->Logg = logg;
		NayaGhar->agla = NULL;
	
		if(PehlaGhar == NULL)
		{
			PehlaGhar = NayaGhar;
		}
		else
		{
			struct Ghar * temp = PehlaGhar;
			while(temp->agla!=NULL)
			{
					temp = temp->agla;
			}
			temp->agla = NayaGhar;
		}
	}
	printf("\nGuest House Bann gaye\n");
}
void display()
{
	if(PehlaGhar==NULL)
	{
		printf("\nGhar khali hai!!!\n");
	}
	else
	{
		struct Ghar *temp = PehlaGhar;
		while(temp != NULL)
		{	
			printf("%d->",temp->Logg);
			temp = temp->agla;
		}
		printf("NULL");
	}
}
void main()
{
	int n;
	printf("\nKitne Ghar banane hai: ");
	scanf("%d",&n);
	create(n);
	display();
}
