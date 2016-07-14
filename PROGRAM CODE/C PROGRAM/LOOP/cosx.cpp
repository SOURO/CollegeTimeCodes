#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int i,j,k=-1;
	long unsigned int den=1;
	float sn=1,num,deg,rad,tn;
	clrscr();
	printf("enter any value in degree");
	scanf("%f",&deg);
	rad=deg*(3.142/180);
	for(i=1;i<=10;i++)
	{
		num=pow(rad,(2*i));

		den=den*(2*i);

		tn=k*(num/den);
		k=-k;
		sn=sn+tn;
	}
	printf("the cosine of given value is=%f",sn);
	getch();
}
