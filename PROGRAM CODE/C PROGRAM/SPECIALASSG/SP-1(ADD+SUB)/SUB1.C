#include<stdio.h>
#include<conio.h>

long unsigned sub(long unsigned,long unsigned);
void present(long unsigned,long unsigned,long unsigned);

int bor[50],j=0;

void main()

{

	long unsigned num1,num2,n1,n2,sub1;

	clrscr();

	printf("\nENTER A NUMBER:\n");
	scanf("%lu",&num1);

	printf("\nENTER ANOTHER NUMBER\n");
	scanf("%lu",&num2);

	n1=num1;
	n2=num2;

	if(num1<num2)
	   sub1=sub(num2,num1);

	else
	   sub1=sub(num1,num2);

	present(sub1,n1,n2);

	printf("\n\n\t\t**.CONGRATS..YOUR OPERATION IS SUCESSFUL..**");

	getch();
}

long unsigned sub(long unsigned num1,long unsigned num2)

{
	long unsigned n11,n22,sub1=0;
	int borrow=0,arr[50],k,i=0;

	while(num1!=0&&num2!=0)
	{

		n11=num1%10;
		n22=num2%10;

		if(n11<n22)
		{
			n11=n11-borrow;
			arr[i++]=(n11+10)-n22;
			borrow=1;
			bor[j++]=borrow;

		}

		else
		{
			n11=n11-borrow;
			arr[i++]=n11-n22;
			borrow=0;
			bor[j++]=borrow;
		}

		num1=num1/10;
		num2=num2/10;
	}

	while(num1!=0)
	{

	   n11=num1%10;
		arr[i++]=n11-borrow;
		borrow=0;
		num1=num1/10;

	}
	for(k=i-1;k>=0;k--)
	{

		sub1=(sub1*10)+arr[k];
	}
	return sub1;
}

void present(long unsigned sub1,long unsigned n1,long unsigned n2)
{
	int l;

	printf("\n\nTHE SUBTRACTION IS\t:\n\n");
	printf("\nBORROWERS ARE RESPECTIVELY: ");

	for(l=j-1;l>=0;l--)

		printf("%d",bor[l]);

	printf("\n\t\t\t    _ _ _ _ _ _ \n");

	printf("\n\n\n\t\t\t    %10lu",n1);
	printf("\n\t\t\t-");
	printf("\n\t\t\t    %10lu",n2);
	printf("\n\t\t\t __________________\n\n");

	if(n1<n2)
		printf("\t\t\t  - %10lu",sub1);

	else
		printf("\t\t\t    %10lu",sub1);
}










