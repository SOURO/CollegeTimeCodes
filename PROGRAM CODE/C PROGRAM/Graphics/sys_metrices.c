#include<dos.h>
#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<graphics.h>

char *fonts[]={
			   "Default_Font","Triplex_Font","Small_Font",
			   "Sansserif_Font","Gothic_Font","Script_Font",
			   "Simplex_Font","Triplex_Font","Complex_Font",
			   "European_Font","Bold_Font"
			  };

char *linestyles[]={
					"Solid_Line","Dotted_Line","Center_Line",
					"Dashed_Line","UserBit_Line"
				   };

char *fillstyles[]={"EMPTY_FILL","SOLID_FILL","LINE_FILL",
					 "LTSLASH_FILL","SLASH_FILL","BKSLASH_FILL",
					 "LTBKSLASH_FILL","HATCH_FILL","XHATCH_FILL",
					 "INTERLEAVE-FILL","WIDE_DOT_FILL",
					 "CLOSE_DOT_FILL"
					};

char *textdirect[]={
					"Horiz_Dir","Vert_Dir"
				   };

char *horizontal[]={
					"Left_Text","Center_Text","Right_Text"
				   };

char *vertical[]={
				  "Bottom_Text","Center_Text","Top_Text"
				 };

struct pts
{
	int x,y;
};

int gprintf(int *xloc,int *yloc,char *fmt,...)
{
	va_list ptr;
	char str[140];

	va_start(ptr,fmt);
	vsprintf(str,fmt,ptr);
	outtextxy(*xloc,*yloc,str);
	*yloc+=textheight("H")+2;
	va_end(ptr);
	return 0;
}


void main()
{
	struct viewporttype vp;
	struct linesettingstype ls;
	struct fillsettingstype fs;
	struct textsettingstype ts;
	struct palettetype palette,far *pal;

	float aspectratio;
	int maxx,maxy,maxcolor,errorcode,xasp,yasp,low,high;

	char *driver,*mode;
	int x,y,gd=DETECT,gm,i;

	initgraph(&gd,&gm,"d:\\tc\\bgi");

	rectangle(0,20,639,479);
	outtextxy(200,10,"SYSTEM METRICS");


	getviewsettings(&vp);
	getlinesettings(&ls);
	getfillsettings(&fs);
	gettextsettings(&ts);
	getpalette(&palette);
	getaspectratio(&xasp,&yasp);
	aspectratio=xasp/yasp;
	driver=getdrivername();
	mode=getmodename(gm);
	getmoderange(gd,&low,&high);
	gm=getgraphmode();
	maxcolor=getmaxcolor()+1;
	pal=getdefaultpalette();

	x=20;
	y=30;

	settextjustify(LEFT_TEXT,TOP_TEXT);

	gprintf(&x,&y,"Graphics device :%-20s(%d)",driver,gd);
	gprintf(&x,&y,"Graphics mode   :%-20s(%d)",mode,gm);
	gprintf(&x,&y,"Maximum Mode Number :%-20s(%d)",getmaxmode());
	gprintf(&x,&y,"Mode Range is   :%d to %d",low,high);
	gprintf(&x,&y,"Screen Resolution :(0,0,%d,%d)",getmaxx(),getmaxy());
	gprintf(&x,&y,"Current View Port :(%d,%d,%d,%d)",vp.left,vp.top,vp.right,vp.bottom);
	gprintf(&x,&y,"Clipping        :%s",vp.clip?"ON":"OFF");
	gprintf(&x,&y,"Aspect Ratio    :%f",aspectratio);
	gprintf(&x,&y,"Current Position:(%d,%d)",getx(),gety());
	gprintf(&x,&y,"Colors available:%d",maxcolor);
	gprintf(&x,&y,"Current Color   :%d",getcolor());
	gprintf(&x,&y,"Current Backcolor:%d",getbkcolor());
	gprintf(&x,&y,"Line Style      :%s",linestyles[ls.linestyle]);
	gprintf(&x,&y,"Line Thickness  :%d",ls.thickness);
	gprintf(&x,&y,"Current Fill Style:%s",fillstyles[fs.pattern]);
	gprintf(&x,&y,"Current Fill Color:%d",fs.color);
	gprintf(&x,&y,"Current Font    :%s",ts.font);
	gprintf(&x,&y,"Text Direction  :%s",textdirect[ts.direction]);
	gprintf(&x,&y,"Character Size  :%d",ts.charsize);
	gprintf(&x,&y,"Horizontal Justify:%s",horizontal[ts.horiz]);
	gprintf(&x,&y,"Vertical Justify:%s",vertical[ts.vert]);
	gprintf(&x,&y,"Palette Size    :%d",getpalettesize());

	for(i=0;i<=15;i++)
		gprintf(&x,&y,"Value of color[%d]=%d",i,pal->colors[i]);

	getch();
	closegraph();
	restorecrtmode();
}