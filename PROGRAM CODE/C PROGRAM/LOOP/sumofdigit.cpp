#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n,a,sum;
	sum=0;
	clrscr();
	printf("enter any number");
	scanf ("%d",&n);
	while(n!=0)
	{
		a=n%10;
		sum=(sum+a);
		n=n/10;
	}
	printf("the sumation of all digits is %d",sum);
	getch();
}
