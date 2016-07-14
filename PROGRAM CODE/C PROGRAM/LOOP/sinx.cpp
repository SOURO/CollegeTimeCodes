#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int i,j,k=1;
	long unsigned int den=1;
	float sn=0,num,deg,rad,tn;
	clrscr();
	printf("enter any value in degree");
	scanf("%f",&deg);
	rad=deg*(3.142/180);
	for(i=1;i<=10;i++)
	{
		num=pow(rad,(2*i-1));
		for(j=1;j<=(2*i)-1;j++)
		{
			den=den*j;
		}
		tn=k*(num/den);
		k=-k;
		sn=sn+tn;
	}
	printf("the value of sin is=%f",sn);
	getch();
}
