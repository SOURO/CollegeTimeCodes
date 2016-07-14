#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i;
	float a,d,tn,sn=0;
	clrscr();
	printf("enter:\nthe first term\ncommon differnce\nnumber of terms for summation\n");
	scanf("%f %f %d",&a,&d,&n);
	printf("\nthe AP series is");
	for(i=1;i<=n;i++)
	{
		tn=a+(i-1)*d;
		printf("\t%f",tn);
		sn=sn+tn;
	}
	printf("\nthe sumation of AP series is=%f",sn);
	getch();
}
