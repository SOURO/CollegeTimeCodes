#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,k,n,a=10;
	clrscr();

	for(i=4;i>=1;i--)
	{
		for(k=4;k>=i-4;k--)
		{

			printf(" ");
		}
		for(j=i;j>=1;j--)
		{
			printf("%d",a);
			a=a-1;
		}
		printf("\n");
	}
	getch();
}