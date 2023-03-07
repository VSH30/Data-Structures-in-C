#include<stdio.h>

void main()
{
	int i = 6;
	int p;
	
	p = &i;
	
	printf("%d F",i);
	printf("%d F",&i);
	printf("%d F",p);
	printf("%d F",p);
}
