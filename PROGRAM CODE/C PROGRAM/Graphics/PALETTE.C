#include<graphics.h>
#include<stdlib.h>
void main()
{
	int gd=DETECT,gm,x,y,i,j,color,startcolor,height,width;
	struct palettetype palette;
	struct viewporttype vp;

	initgraph(&gd,&gm,"D:\\TC\\BGI");

	getpalette(&palette);

	setcolor(WHITE);
	rectangle(0,14,639,479);
	outtextxy(200,5,"PALETTE DEMONSTRATION");

	getviewsettings(&vp);
	width=(vp.right-vp.left)/16;
	height=(vp.bottom-vp.top-20)/16;
	x=0;
	y=15;
	startcolor=0;
	for(j=0;j<16;j++)
	{
		color=startcolor;
		for(i=0;i<16;i++)
		{
			setfillstyle(SOLID_FILL,color++);
			bar(x,y,x+width,y+height);
			x=x+width+1;
		}
		startcolor++;
		x=0;
		y=y+height+1;
	}
	getch();


	while(!kbhit())
	{
		setpalette(random(16),random(65));
		delay(300);
	}


	setallpalette(&palette);

	getch();
	closegraph();
	restorecrtmode();
}