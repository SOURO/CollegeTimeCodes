#include<stdio.h>
#include<conio.h>
void main()
{
	int i,s,j,n;
	clrscr();
	printf("\nEnter upto how which number you want to check for perfect number\n");
	scanf("%d",&n);
	for(j=1;j<=n;j++)
	{
		s=0;
		for(i=1;i<=j/2;i++)
			if(j%i==0)
				s=s+i;
		if(s==j)
			printf("\n%d is a perfect number\n",j);
		else
			printf("\n%d is not a perfect number\n",j);
	}
	getch();
}
