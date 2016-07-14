#include<stdio.h>
#include<conio.h>
void main()
{
	int i,mul,n;
	clrscr();
	printf("enter the no. whose periodical table you want");
	scanf("%d",&n);
	for(i=1;i<=10;i++)
	{
		mul=n*i;
		printf("\n %2d x %2d =%2d",n,i,mul);
	}
	getch();
}