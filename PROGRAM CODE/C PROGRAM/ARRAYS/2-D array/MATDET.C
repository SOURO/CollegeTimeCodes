#include<stdio.h>
#include<conio.h>
void main()
{
	int m1[10][10],i,j,m,n,t1,t2,det;
	clrscr();
	printf("enter the order of the matrix ");
	scanf("%d%d",&m,&n);
	printf("enter %d elements of matrix ",m*n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&m1[i][j]);
		}
	}
	det=0;
	for(i=0;i<n;i++)
	{
		t1=m1[1][(i+1)%3]*m1[2][(i+2)%3];
		t2=m1[1][(i+2)%3]*m1[2][(i+1)%3];
		det+=m1[0][i]*(t1-t2);
	}
	printf("\n after matrix determinant %d\n" ,det);
	getch();
}
