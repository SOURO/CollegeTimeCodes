#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int n,i;
	float a,r,tn,sn=0;
	clrscr();
	printf("enter:\nthe first term\ncommon ratio\nnumber of terms for summation\n");
	scanf("%f %f %d",&a,&r,&n);
	printf("\nthe GP series is");
	for(i=1;i<=n;i++)
	{
		tn=a*pow(r,i-1);
		printf("\t%f",tn);
		sn=sn+tn;
	}
	printf("\nthe sumation of GP series is=%f",sn);
	getch();
}
