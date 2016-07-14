#include<graphics.h>
#include<conio.h>
void main()
{
	int gd=DETECT,gm,x,y,i;
	int array[]={540,220,590,270,570,320,510,320,490,270,540,220};

	char str[10];
	struct linesettingstype ls;

	initgraph(&gd,&gm,"c:\\tc\\bgi");

	x=getmaxx();  // x=640
	y=getmaxy();  // y=480

	setcolor(WHITE);
	rectangle(0,0,x,y);

	setcolor(GREEN);
	for(i=0;i<10;i++)
		rectangle(x/30+i,y/20+i,x/5+i,y/4+i);
	outtextxy(x/30+20,y/8+15,"RECTENGLE");

	for(i=0;i<5;i++)
		circle(x/2,y/6,75-i);
	putpixel(x/2,y/6,WHITE);
	outtextxy(x/2-textwidth("CIRCLE")/2,y/6+10,"CIRCLE");

	arc(x/1.2,y/6,250,70,80);
	putpixel(x/1.2,y/6,WHITE);
	outtextxy(x/1.2+5,y/6,"ARC");

	line(x/30,8*y/15,x/6,8*y/15);
	outtextxy(x/30+20,8*y/15+10,"LINE");

	setlinestyle(1,0,1);
	moveto(x/30,9*y/15);
	lineto(x/6,9*y/15);
	outtextxy(x/30+30-textwidth("(lineto)")/2,9*y/15+10,"LINE(lineto)");

	setlinestyle(3,0,1);
	moveto(x/6,9*y/15);
	moverel(0,y/15);
	linerel(x/30-x/6,0);
	outtextxy(x/30+30-textwidth("(linerel)")/2,10*y/15+10,"LINE(linerel)");

	ellipse(x/2,10*y/17,0,360,100,50);
	putpixel(x/2,10*y/17,WHITE);
	outtextxy(x/2-textwidth("ELLIPSE")/2,10*y/17+10,"ELLIPSE");

	drawpoly(6,array);
	outtextxy(512,270,"POLYGON");

	setcolor(YELLOW);
	for(i=0;i<=4;i++)
	{
		setlinestyle(i,0,1);

		if(i==0)
			getlinesettings(&ls);

		if(i==4)
			setlinestyle(4,15,1);

		line(x/30,11*y/15,x/30,y-2);

		itoa(i,str,10);
		outtextxy(x/30+5,y-20,str);
		x=x+600;
	}

	setlinestyle(ls.linestyle,ls.upattern,ls.thickness);

	getch();
	closegraph();
	restorecrtmode();
}