#include<stdio.h>
#include<conio.h>
float df(float x,float y)
{
	return(x+y);
}
void main()
{
	float x0,y0,x1,y1,x,h;
	int n,i;
	clrscr();
	printf("\nEnter the initial value of x & y");
	scanf("%f%f",&x0,&y0);
	printf("\nEnter size of each step :");
	scanf("%f",&h);
	printf("\nEnter total no. of step :");
	scanf("%d",&n);
	printf("\nEnter x for which you find y : ");
	scanf("%f",&x);
	x1=x0;
	y1=y0;
	printf("\nEuler's modified method for solving y'=x+y");
	printf("\n\tx\t\t\ty-mod");
	printf("\n\t%0.4f\t\t\t0.4f",x1,y1);
	for(i=1;i<=n;i++)
	{
		y1=(y1+h*df((x1+h/2),(y1+h/2)*df(x1,y1)));
		x1=x1+h;
		printf("\n\t%0.4f\t\t\t%0.4f",x1,y1);
	}
	printf("\n\n\tFinal result : When x=%0.4f,y=%0.4f",x,y1);
	getch();
}