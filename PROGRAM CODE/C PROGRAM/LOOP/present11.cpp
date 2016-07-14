#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,k,n,a=0;
	clrscr();
	printf("enter the number of terms");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(k=1;k<=n-i;k++)
		{
			printf(" ");
		}
		for(j=1;j<=i;j++)
		{
			a=a+1;
			printf("%2d",a);
		}
		printf("\n");
	}
	getch();
}