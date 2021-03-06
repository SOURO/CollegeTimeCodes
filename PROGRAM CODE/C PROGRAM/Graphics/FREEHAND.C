#include<graphics.h>
#include<dos.h>

union REGS i,o;

int initmouse()
{
	i.x.ax=0;
	int86(0x33,&i,&o);
	return(o.x.ax);
}

void showmouseptr()
{
	i.x.ax=1;
	int86(0x33,&i,&o);
}

void hidemouseptr()
{
	i.x.ax=2;
	int86(0x33,&i,&o);
}

void restrictmouseptr(int x1,int y1,int x2,int y2)
{
	i.x.ax=7;
	i.x.cx=x1;
	i.x.dx=x2;
	int86(0x33,&i,&o);
	i.x.ax=8;
	i.x.cx=y1;
	i.x.dx=y2;
	int86(0x33,&i,&o);
}

void getmousepos(int *button,int *x,int *y)
{
	i.x.ax=3;
	int86(0x33,&i,&o);
	*button=o.x.bx;
	*x=o.x.cx;
	*y=o.x.dx;
}

void main()
{
	int gd=DETECT,gm,maxx,maxy,x,y,button,prevx,prevy;

	initgraph(&gd,&gm,"D:\\TC\\BGI");
	maxx=getmaxx();
	maxy=getmaxy();

	rectangle(0,10,maxx,maxy);
	outtextxy(200,2,"FREE HEAND DRAWING");
	setviewport(1,1,maxx-1,maxy-1,1);

	if(initmouse()==0)
	{
		closegraph();
		restorecrtmode();
		printf("\nMouseDriver not loaded");
		exit(0);
	}

	restrictmouseptr(1,11,maxx-1,maxy-1);
	showmouseptr();

	while(!kbhit())
	{
		getmousepos(&button,&x,&y);
		if((button&1)==1)
		{
			hidemouseptr();
			prevx=x;
			prevy=y;

			while((button&1)==1)
			{
				line(prevx,prevy,x,y);
				prevx=x;
				prevy=y;
				getmousepos(&button,&x,&y);
			}

			showmouseptr();
		}
	}
}