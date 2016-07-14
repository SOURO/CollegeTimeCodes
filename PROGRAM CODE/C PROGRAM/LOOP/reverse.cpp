#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n,a,rev;
	rev=0;
	clrscr();
	printf("enter any number");
	scanf ("%d",&n);
	while(n!=0)
	{
		a=n%10;
		rev=((rev*10)+a);
		n=n/10;
	}
	printf("the reverse number is %d",rev);
	getch();
}
