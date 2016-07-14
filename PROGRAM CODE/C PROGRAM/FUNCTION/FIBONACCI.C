#include<stdio.h>
#include<conio.h>

void fibo(int); //function decleration

int n;//global variable

void main()
{
	clrscr();
	printf("\n\nENTER UPTO HOW MUCH TERM YOU WANT TO GET FIBO SERIES::\n");
	scanf("%d",&n);
	printf("\nTHE FIBONACI SERIES UPTO %d TERMS IS::\n\n",n);
	fibo(1);
	getch();
}

void fibo(int i)
{
	int c;
	static int a,b=1;

	if(i==1)
		printf("%d ",a);

	else if(i==2)
		printf("%d ",b);

	else if(i<=n)
	{
		c=a+b;
		printf("%d ",c);
		a=b;
		b=c;
	}

	if(i<n)
		fibo(i+1);
}