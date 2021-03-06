#include<graphics.h>
void main()
{
	int gd=DETECT,gm,maxx,maxy,x=10,y=40,i,j=10,k;
	char str[10];
	char pattern[][8]=
	{
		{0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55},
		{0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC},
		{0xF0,0xF0,0xF0,0xF0,0x0F,0x0F,0x0F,0x0F},
		{0x00,0x10,0x28,0x44,0x28,0x10,0x00,0x00},
		{0x00,0x70,0x20,0x27,0x24,0x24,0x07,0x00},
		{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
		{0x00,0x00,0x3C,0x3C,0x3C,0x3C,0x00,0x00},
		{0x00,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x00},
		{0x00,0x00,0x22,0x08,0x00,0x22,0x1C,0x00},
		{0xFF,0x7E,0x3C,0x18,0x18,0x3C,0x7E,0xFF},
		{0x00,0x10,0x10,0x7C,0x10,0x10,0x00,0x00},
		{0x00,0x42,0x24,0x18,0x18,0x24,0x42,0x00}
	};
	char *patterns[]={
					 "EMPTY_FILL","SOLID_FILL","LINE_FILL",
					 "LTSLASH_FILL","SLASH_FILL","BKSLASH_FILL",
					 "LTBKSLASH_FILL","HATCH_FILL","XHATCH_FILL",
					 "INTERLEAVE_FILL","WIDE_DOT_FILL",
					 "CLOSE_DOT_FILL","USER_FILL"
					};

	initgraph(&gd,&gm,"d:\\tc\\bgi");


	maxx=getmaxx();
	maxy=getmaxy();
	rectangle(0,10,maxx,maxy);

	setcolor(BLUE);
	outtextxy(175,0,"Pre-defined filling style");

	for(i=0;i<12;i++)
	{
		//setfillstyle(i,GREEN);
		//bar(x,y,x+150,y+80);
		//rectangle(x,y,x+150,y+80);
		//floodfill(x+1,y+1,BLUE);    // IN CASE OF floodfill(), setcolor()
									// & floodfill() SHOULD HAVE SAME COLOR

		for(k=0;k<15;k++)
		{
			setcolor(WHITE);
			setfillstyle(i,k);
			rectangle(x,y,x+150,y+80);
			floodfill(x+1,y+1,WHITE);
			delay(500);
		}


		itoa(i,str,10);
		outtextxy(x+75,y+100,str);
		outtextxy(x+75-textwidth(patterns[i])/2,y+110,patterns[i]);

		x=x+150;
		if(x>600)
		{
			y+=150;
			x=20;
		}
	}
	getch();
	clrscr();

	initgraph(&gd,&gm,"d:\\tc\\bgi");
	x=10;
	y=40;

	rectangle(0,10,maxx,maxy);

	setcolor(WHITE);
	outtextxy(175,0,"Pre-defined filling style");

	for(i=0;i<12;i++)
	{
		setfillstyle(i,GREEN);

		//ellipse((x+x+150)/2,(y+y+80)/2,0,360,75,40);
		//floodfill((x+x+150)/2,(y+y+80)/2,WHITE);    // IN CASE OF floodfill(), setcolor()
									// & floodfill() SHOULD HAVE SAME COLOR

		fillellipse((x+x+150)/2,(y+y+80)/2,75,40); // IN CASE OF fillellipse(),
												   // WE DON'T NEED ellipse()

		itoa(i,str,10);
		outtextxy(x+75,y+100,str);
		outtextxy(x+75-textwidth(patterns[i])/2,y+110,patterns[i]);

		x=x+150;
		if(x>600)
		{
			y+=150;
			x=20;
		}
	}
	getch();
	clrscr();

	initgraph(&gd,&gm,"d:\\tc\\bgi");

	setcolor(CYAN);
	x=10;
	y=20;
	rectangle(0,10,maxx,maxy);

	setcolor(GREEN);
	outtextxy(175,0,"User-defined Fill Style");

	for(i=0;i<12;i++)
	{
		setfillpattern(&pattern[i][0],RED);
		bar(x,y,x+150,y+80);
		rectangle(x,y,x+150,y+80);

		itoa(i,str,10);
		outtextxy(x+75,y+100,str);

		x=x+150;
		if(x>600)
		{
			y+=150;
			x=20;
		}
	}


	getch();
	clrscr();

	initgraph(&gd,&gm,"d:\\tc\\bgi");

	x=10;
	y=20;
	rectangle(0,10,maxx/2-1,maxy);

	setcolor(GREEN);
	outtextxy(60,0,"Pre-defined filling style");

	for(i=0;i<12;i++)
	{
		setfillstyle(i,CYAN);
		//bar(x,y,x+75,y+80);
		//rectangle(x,y,x+75,y+80);
		circle((x+x+75)/2,(y+y+80)/2,35);
		floodfill((x+x+75)/2,(y+y+80)/2,GREEN);

		itoa(i,str,10);
		if(j==10)
			j=0;
		else
			j=10;
		outtextxy(x+37,y+100+j,str);
		outtextxy(x+37-textwidth(patterns[i])/2,y+110+j,patterns[i]);

		x=x+75;
		if(x>300)
		{
			y+=150;
			x=10;
		}
	}
	//getch();
	//clrscr();

	//initgraph(&gd,&gm,"d:\\tc\\bgi");

	setcolor(CYAN);
	x=10;
	y=20;
	rectangle(maxx/2+1,10,maxx,maxy);

	setcolor(MAGENTA);
	outtextxy(maxx/2+60,0,"User-defined Fill Style");

	for(i=0;i<12;i++)
	{
		setfillpattern(&pattern[i][0],i);
		//bar(maxx/2+x,y,maxx/2+x+75,y+80);
		//rectangle(maxx/2+x,y,maxx/2+x+75,y+80);
		circle((maxx+x+x+75)/2,(y+y+80)/2,35);
		floodfill((maxx+x+x+75)/2,(y+y+80)/2,MAGENTA);

		itoa(i,str,10);
		outtextxy(maxx/2+x+37,y+100,str);

		x=x+75;
		if(x>300)
		{
			y+=150;
			x=10;
		}
	}


	getch();
	closegraph();
	restorecrtmode();
}