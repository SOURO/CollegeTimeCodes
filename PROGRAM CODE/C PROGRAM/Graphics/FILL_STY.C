#include<graphics.h>
void main()
{
	int gd=DETECT,gm,maxx,maxy,x=20,y=40,i;
	char str[40];
	char *pattern[]={
					 "EMPTY_FILL","SOLID_FILL","LINE_FILL",
					 "LTSLASH_FILL","SLASH_FILL","BKSLASH_FILL",
					 "LTBKSLASH_FILL","HATCH_FILL","XHATCH_FILL",
					 "INTERLEAVE-FILL","WIDE_DOT_FILL",
					 "CLOSE_DOT_FILL","USER_FILL"
					};

	initgraph(&gd,&gm,"d:\\tc\\bgi");

	maxx=getmaxx();
	maxy=getmaxy();
	rectangle(0,10,maxx,maxy);

	setcolor(RED);
	outtextxy(175,0,"Pre-defined filling style");

	for(i=0;i<12;i++)
	{
		setfillstyle(i,MAGENTA);
		bar(x,y,x+150,y+80);
		rectangle(x,y,x+150,y+80);

		itoa(i,str,10);
		outtextxy(x,y+100,str);
		outtextxy(x,y+110,pattern[i]);

		x=x+150;
		if(x>600)
		{
			y+=150;
			x=20;
		}
	}

	getch();
	closegraph();
	restorecrtmode();
}