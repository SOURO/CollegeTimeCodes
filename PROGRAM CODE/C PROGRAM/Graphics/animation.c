#include<graphics.h>
#include<alloc.h>

void main()
{
	int gd=DETECT,gm,area,x=25,y=25,ch,xdirn=1,ydirn=1,maxx,maxy;
	char *buff;

	initgraph(&gd,&gm,"C:\\TC\\BGI");

	setcolor(GREEN);
	setfillstyle(SOLID_FILL,RED);
	circle(50,50,25);
	floodfill(50,50,GREEN);

	area=imagesize(25,25,75,75);
	buff=malloc(area);
	getimage(25,25,75,75,buff);

	maxx=getmaxx();
	maxy=getmaxy();
	rectangle(0,20,maxx,maxy);
	outtextxy(250,10,"Animation");

	while(1)
	{
		if(kbhit())
		{
			ch=getch();

			if(ch=='\r')
			{
				xdirn=-xdirn;
				ydirn=-ydirn;
			}
			else
			{
				if(ch==27)
					break;
			}
		}

		putimage(x,y,buff,XOR_PUT);
		delay(0);
		x+=xdirn*5;
		y+=ydirn*2;
		putimage(x,y,buff,XOR_PUT);

		if( x>maxx-50 || x<0 )
		{
			sound(50);
			delay(10);
			nosound();
			xdirn=-xdirn;
		}

		if( y>maxy-50 || y<20 )
		{
			sound(50);
			delay(10);
			nosound();
			ydirn=-ydirn;
		}
	}

	getch();
	closegraph();
	restorecrtmode();
}