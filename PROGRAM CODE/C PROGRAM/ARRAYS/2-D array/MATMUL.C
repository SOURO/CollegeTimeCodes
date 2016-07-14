#include<stdio.h>
#include<conio.h>
void main()
{
	int m1[10][10],m2[10][10],m3[10][10],i,j,k,m,n,p;
	clrscr();
	printf(" enter the order of the 1st matrix ");
	scanf("%d%d",&m,&n);
	printf("enter the column of the 2nd matrix ");
	scanf("%d",&p);
	printf("\n enter %d elements for 1st matrix ",m*n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&m1[i][j]);
		}
	}
	printf("\n enter %d elements for 2nd matrix ",n*p);
	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
		{
			scanf("%d",&m2[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<p;j++)
		{
			m3[i][j]=0;
			for(k=0;k<n;k++)
			{
				m3[i][j]+=m1[i][k]*m2[k][j];
			}
		}
	}
	printf("\n after matrix multiplication\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<p;j++)
		{
			printf("%3d",m3[i][j]);
		}
		printf("\n");
	}
	getch();
}

