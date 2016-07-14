#include<stdio.h>
#include<conio.h>
void main()
{
	int m1[10][10],m2[10][10],m3[10][10],i,j,k,m,n;
	clrscr();
	printf(" enter the order of the 1st matrix ");
	scanf("%d%d",&m,&n);
	printf("\n enter %d elements for 1st matrix ",m*n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&m1[i][j]);
		}
	}
	printf("\n enter %d elements for 2nd matrix ",m*n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&m2[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			m3[i][j]=m1[i][j]-m2[i][j];
		}
	}
	printf("\n after matrix substruction\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%3d",m3[i][j]);
		}
		printf("\n");
	}
	getch();
}

