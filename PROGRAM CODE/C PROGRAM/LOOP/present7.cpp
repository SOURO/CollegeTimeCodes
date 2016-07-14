#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,k,a=10;
	clrscr();

	for(i=1;i<=4;i++)
	{
		for(k=1;k<=4-i;k++)
		{
			printf(" ");
		}
		for(j=1;j<=i;j++)
		{

			printf("%d",a);
			a=a-1;
		}
		printf("\n");
	}
	getch();
}