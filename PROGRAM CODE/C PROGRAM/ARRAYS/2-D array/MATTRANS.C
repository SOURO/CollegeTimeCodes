#include<stdio.h>
#include<conio.h>
void main()
{
	int m1[10][10],m2[10][10],m3[10][10],i,j,m,n;
	clrscr();
	printf(" enter the order of the matrix ");
	scanf("%d%d",&m,&n);
	printf("\n enter %d elements for matrix ",m*n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&m1[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			m2[i][j]=m1[j][i];
		}
	}
	printf("\n the matrix\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		       printf("%3d",m1[i][j]);
		}
		printf("\n");
	}
	printf("\n after matrix transpose\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%3d",m2[i][j]);
		}
		printf("\n");
	}
	getch();
}

