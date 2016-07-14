#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void bline(int,int,int,int);

void main()
{
	int x1,y1,x2,y2,gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	printf("Enter the value of two coordinates:\n");
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	bline(x1,y1,x2,y2);
	getch();
	closegraph();
	restorecrtmode();
}

void bline(int x1,int y1,int x2,int y2)
{
	int m,x,y,p,dy,dx;
	m=(y2-y1)/(x2-x1);

	dy=y2-y1;
	dx=x2-x1;

	x=x1;
	y=y1;

	if(m<=1)
	{

		p=2*dy-dx;
		while(x<=x2)
		{
		  putpixel(x,y,4);
		  if(p>0)
		  {
			x+=1;
			y+=1;
			p+=2*(dy-dx);
		  }
		  if(p>0)
		  {
			x+=1;
			p+=2*dy;
		  }
		}

	}
	else
	{

		p=2*dx-dy;
		while(y<=y2)
		{
		  putpixel(x,y,4);
		  if(p>0)
		  {
			x+=1;
			y+=1;
			p+=2*(dx-dy);
		  }
		  if(p>0)
		  {
			y+=1;
			p+=2*dx;
		  }
		}

	}
}



