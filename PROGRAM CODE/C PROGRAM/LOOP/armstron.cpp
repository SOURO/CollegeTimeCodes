#include<stdio.h>
#include<conio.h>
void main()
{
	int n,a,sum,num;
	sum=0;
        n=num;
	clrscr();
	printf("enter any number");
	scanf ("%d",&n);
	while(n!=0)
	{
		a=n%10;
		sum=(a*a*a)+sum;
		n=n/10;
	}
	if(num==sum)
	{
		printf("\nthe given number is armstrong number");
	}
	else
	{
		printf("\nthe given number is not armstrong number");
	}
	getch();
}
