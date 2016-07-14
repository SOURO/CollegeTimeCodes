#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int i;
	long unsigned int den=1;
	float sn=1,num,x,tn;
	clrscr();
	printf("enter the value of x");
	scanf("%f",&x);
	for(i=1;i<=10;i++)
	{
		num=pow(x,i);

		den=den*i;

		tn=(num/den);

		sn=sn+tn;
	}
	printf("the exponential value is=%f",sn);
	getch();
}
