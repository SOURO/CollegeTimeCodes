#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n,a,rev,num;
	n=num;
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
	if(rev==num)
	{
		printf(" the given number is palindrom number");
	}
	else
	{
		printf(" the given number is not a palindrom number");
	}

	getch();
}
