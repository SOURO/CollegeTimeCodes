 #include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,k,n;
	clrscr();
	printf("enter the number of terms");
	scanf("%d",&n);
	for(i=n;i>=1;i--)
	{
		for(k=n;k>=i-n;k--)
		{
			printf(" ");
		}
		for(j=i;j>=1;j--)
		{
			printf(" *");
		}
		printf("\n");
	}
	getch();
}