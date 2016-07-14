#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void dda(int,int,int,int);

void main()
{
	int x1,y1,x2,y2,gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	printf("Enter the value of two coordinates:\n");
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	dda(x1,y1,x2,y2);
	getch();

	closegraph();
	restorecrtmode();

}

void dda(int x1,int y1,int x2,int y2)
{
	int m,x,y;
	m=(y2-y1)/(x2-x1);
	x=x1;
	y=y1;
	putpixel(x,y,4);
	if(m<=1)
	{
		while(x<=x2)
		{
		  x+=1;
		  y+=m;
		 putpixel(x,y,4);
		}

	}
	else
	{
		while(y<=y2)
		{
		  x+=(1/m);
		  y+=1;
		   putpixel(x,y,4);
		}

	}
}


