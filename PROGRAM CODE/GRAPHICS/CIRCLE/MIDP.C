#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void midpoint(int,int,int);
void setpixel(int,int,int,int,int);

void main()
{
	int r,gd=DETECT,gm,xcentre=70,ycentre=90,i;

	initgraph(&gd,&gm,"c:\\tc\\bgi");

	printf("Enter the value of radius");
	scanf("%d",&r);

	midpoint(r,xcentre,ycentre);
	getch();

	closegraph();
	restorecrtmode();
}

void midpoint(int r,int xcentre,int ycentre)
{
	int color=4;
	int p=1-r;
	int x=0;
	int y=r;
	while(x<=y)
	{
		setpixel(x,y,xcentre,ycentre,color);
		if(p>0)
		{
			x=x+1;
			y=y-1;
			p=p+2*(x-y)+5;
		}
		else if(p<0)
		{
			x=x+1;
			p=p+2*x+3;
		}
	}
}

void setpixel(int x,int y,int xcentre,int ycentre,int c)
{
	putpixel(xcentre+x,ycentre+y,c);
	putpixel(xcentre+y,ycentre+x,c);
	putpixel(xcentre+y,ycentre-x,c);
	putpixel(xcentre+x,ycentre-y,c);
	putpixel(xcentre-x,ycentre-y,c);
	putpixel(xcentre-y,ycentre-x,c);
	putpixel(xcentre-y,ycentre+x,c);
	putpixel(xcentre-x,ycentre+y,c);
}

