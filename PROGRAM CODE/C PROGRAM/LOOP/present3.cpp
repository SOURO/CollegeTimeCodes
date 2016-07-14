#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,n,k;
	clrscr();
	printf("enter the no of times");
	scanf("%d",&n);
	for(i=n;i>=1;i--)
	{
		for(k=n;k>=i-n;k--)
		{
		printf(" ");
		}
		for(j=n;j>n-i;j--)
		{
			printf("%d",j);
		}
		printf("\n");
	}
	getch();
}