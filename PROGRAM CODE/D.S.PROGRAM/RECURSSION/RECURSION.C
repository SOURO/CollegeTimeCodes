#include<stdio.h>
#include<conio.h>

int n;           //Number of terms in fibonacci series

long unsigned factorial(int,long unsigned);
void fibo();
void TOH(char,char,char,int);


void main()
{
	int num1,num2,ch;
	long unsigned ans;
	char from,to,aux;
	while(1)
	{
		clrscr();

		printf("\t\t\t*****PROGRAMS USING TAIL RECURSION*****");
		printf("\n\t\t\t   -----------------------------\n\n");
		printf("\nFOR FACTORIAL      =PRESS 1\n");
		printf("\nFOR FIBBONACI      =PRESS 2\n");
		printf("\nFOR TOWER OF HONOI =PRESS 3\n");
		printf("\nFOR EXIT           =PRESS 4\n");

		printf("\n\nENTER YOUR CHOICE::");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("\n\nINPUT THE NUMBER FOR FACTORIAL::");
				scanf("%d",&num2);
				ans=factorial(num2,1);
				printf("\n(%d)! = %d",num2,ans);
				break;
			case 2:
				printf("\n\nINPUT THE NO.OF TERMS FOR FIBBONACI SERIES::\n");
				scanf("%d",&n);
				fibo();
				break;
			case 3:
				printf("\n\nINPUT THE NO. OF DISKS::");
				scanf("%d",&num1);
				printf("\n\nTHE MOVES ARE::\n");
				TOH('C','A','B',num1);
				break;
			case 4:
				printf("\n\nTHANK YOU FOR USING THIS PROGRAM..");
				getch();
				exit(0);
		}
		getch();
	}
}


long unsigned factorial(int num,long unsigned fact)
{
	if(num==1)
		return fact;
	else
		return factorial(num-1,num*fact);
}


void fibo()
{
	int c;
	static int a,b=1,cnt;
	cnt++;
	printf("%d  ",a);
	if(cnt<=n)
	{
		c=a+b;
		a=b;
		b=c;
	}
	if(cnt<n)
		fibo();

}


void TOH(char FROM,char TO,char AUX,int N)
{
	if(N==1)
	{
		printf("\t\t%c --> %c\n",FROM,TO);
		getch();
	}
	else
	{
		TOH(FROM,AUX,TO,N-1);
		TOH(FROM,TO,AUX,1);
		TOH(AUX,TO,FROM,N-1);
	}
}