//VSH
#include<stdio.h>
#include<conio.h>

int vsh(int a, int b)
{
	int v,check=99;
	for(v=2;v<a;v++)
	{
		if(a%v==0)
			check++;
	}
	
	if((b-a)<2)
	{
		return check++;
	}
	else
	{
		for(v=2;v<(b-a);v++)
		{
			if((b-a)%v==0)
				check++;
		}
	}
	return check;
}

void main()
{
	int v,s=99,h;
	while(1)
	{
		s=99;
		printf("\n\nEnter a number: ");
		scanf("%d",&v);
		if(v==3004)
			return;
		if(v<2)
		{
			printf("\nNumber less than 2!!!");
		}
		else
		{
			for(h=2;h<=(v/2);h++)
			{
				if(vsh(h,v)==99)
				{
					printf("\n %d = %d + %d",v,h,(v-h));
					s++;
				}
			}
		}
		if(s==99)
			printf("\nNot possible Sry");
	}
	getch();
}
