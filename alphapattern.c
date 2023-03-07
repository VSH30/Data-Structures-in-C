//VSH
#include <stdio.h>
#include<conio.h>

int main()
{
	int v, s, h;
	printf("Enter number of rows\n");
	scanf("%d", &v);

	for (h = 1; h <= v; h++)
	{
		for (s = 1; s <= v-h; s++)
			printf(" ");
		for (s = 1; s <= 2*h-1; s++)
			printf("%c",'A' + s-1);
	
		printf("\n");
	}

	for (h = 1; h <= v - 1; h++)
	{
		for (s = 1; s <= h; s++)
			printf(" ");
		for (s = 1 ; s <= 2*(v-h)-1; s++)
			printf("%c",'A' +s-1);

		printf("\n");
	}
	
	getch();
}
