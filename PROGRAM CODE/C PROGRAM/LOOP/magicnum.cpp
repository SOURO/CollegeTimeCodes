#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int n,a,sum;
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
	if(sum==10)
	{
		printf("\nthe given number is magic number");
	}
	else
	{
		printf("\nthe given number is not a magic number");
	}
	getch();
}
