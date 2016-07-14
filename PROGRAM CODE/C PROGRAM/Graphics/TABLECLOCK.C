#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<string.h>

#define pi 3.1413

void main()
{
	int gd=DETECT,gm,maxx,maxy;
	int i,j,c,x1,x2,y1,y2;
	int key,start=0;
	int sh,mh,hh;
	float a,b,rad,sx,sy,srad,mx,my,mrad,hx,hy,hrad,osrad,omrad,ohrad;
	union REGS in,out;
	int ss,mm,hr,oldss;
	char str[40],ostr[40],strhr[10],strmm[10],strss[10];


	initgraph(&gd,&gm,"D:\\TC\\BGI");

	maxx=getmaxx();
	maxy=getmaxy();

	setcolor(YELLOW);
	rectangle(25,25,maxx-20,maxy-20);

	setcolor(RED);

	settextstyle(0,0,3);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	outtextxy(maxx/2-textwidth("TABLE CLOCK")/2,0,"TABLE CLOCK");

	rectangle(26,26,maxx-21,maxy-21);
	floodfill(27,27,RED);

	// to make background of clock green
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,GREEN);
	circle(maxx/2,maxy/2,100);
	floodfill(maxx/2,maxy/2,BLACK);

	// sets 3 & 9 th hour bar
	setlinestyle(SOLID_LINE,0,3);
	line(maxx/2+94,maxy/2,maxx/2+99,maxy/2);
	line(maxx/2-99,maxy/2,maxx/2-94,maxy/2);

	// sets 6th hour bar
	line(maxx/2-2,maxy/2+94,maxx/2-2,maxy/2+99);
	line(maxx/2+2,maxy/2+94,maxx/2+2,maxy/2+99);

	//sets 12th hour bar
	line(maxx/2-2,maxy/2-99,maxx/2-2,maxy/2-94);
	line(maxx/2+2,maxy/2-99,maxx/2+2,maxy/2-94);

	// to draw other hour bars & minute points
	setlinestyle(SOLID_LINE,0,1);
	for(i=0;i<12;i++)
		for(j=0;j<5;j++)
		{
			rad=i*(pi/6.0)+j*(pi/30.0);
			if(j>0)
			{
				c=97;
				x1=maxx/2+c*cos(rad);
				y1=maxy/2-c*sin(rad);
				setcolor(RED);
				circle(x1,y1,1);
			}
			else
			{
				if(i%3!=0)
				{
					c=96;
					x1=maxx/2+c*cos(rad);
					y1=maxy/2-c*sin(rad);
					setcolor(RED);
					setfillstyle(SOLID_FILL,MAGENTA);
					circle(x1,y1,2);
					floodfill(x1,y1,RED);
				}
			}
		}

	// Marking 3,6,9 & 12 th hour bar and the company name
	setcolor(MAGENTA);
	settextstyle(0,0,0);
	outtextxy(maxx/2-textwidth("TIMEX")/2+2,maxy/2-75,"TIMEX");
	outtextxy(maxx/2-textwidth("6")/2+1,maxy/2+87-textheight("6")/2,"6");
	outtextxy(maxx/2-textwidth("12")/2-1,maxy/2-87-textheight("12")/2,"12");
	outtextxy(maxx/2-textwidth("3")/2+87,maxy/2+1-textheight("3")/2,"3");
	outtextxy(maxx/2-textwidth("9")/2-86,maxy/2+1-textheight("9")/2,"9");

	outtextxy(maxx/2-textwidth("PRESS Esc KEY TO EXIT")/2,maxy-12,"PRESS Esc KEY TO EXIT");

	// setting hour,minute & second hand lenth of clock
	sh=80;
	mh=65;
	hh=50;
	while(1)
	{
		if(kbhit())
		{
			key=getch();
			if(key==27)
			{
				closegraph();
				restorecrtmode();
				exit();
			}
		}

		// to get CMOS time in BCD format
		in.h.ah=0x02;
		int86(0x1A,&in,&out);
		setcolor(RED);
		sprintf(str,"%x:%x:%x",out.h.ch,out.h.cl,out.h.dh);

		// to get CMOS time in DECIMAL format
		sscanf(str,"%d:%d:%d",&hr,&mm,&ss);

		// set oldss to ss only at the start
		if(start==0)
			oldss=ss;

		if((oldss+1)%60==ss || start==0)
		{

			// to present two digit format of hour, minute & second
			if(hr%12>=0 && hr%12<=9)
				sprintf(strhr,"0%d",hr);
			else
				sprintf(strhr,"%d",hr);
			if(mm>=0 && mm<=9)
				sprintf(strmm,"0%d",mm);
			else
				sprintf(strmm,"%d",mm);
			if(ss>=0 && ss<=9)
				sprintf(strss,"0%d",ss);
			else
				sprintf(strss,"%d",ss);

			// to construct system display
			strcpy(str,strhr);
			strcat(str,":");
			strcat(str,strmm);
			strcat(str,":");
			strcat(str,strss);

			// to set time as AM/PM
			if(hr/12==0)
				strcat(str," AM");
			else
				strcat(str," PM");

			// changing hour,minute & second hands position
			hr%=12;
			srad=pi/2.0-ss*(pi/30.0);
			mrad=pi/2.0-mm*(pi/30.0)-ss*(pi/1800.0);
			hrad=pi/2.0-hr*(pi/6.0)-mm*(pi/360.0)-ss*(pi/21600.0);


			// setting hour,minute & second hands position
			if(srad<=0.0)
				srad+=2*pi;

			if(mrad<=0.0)
				mrad+=2*pi;

			if(hrad<=0.0)
				hrad+=2*pi;

			settextstyle(0,0,2);

			if(start==1)
			{
				// increase oldss which is currently 2 short of ss
				oldss++;
				oldss%=60;

				// to clear the previous position of second hand
				sx=maxx/2+sh*cos(osrad);
				sy=maxy/2-sh*sin(osrad);
				setcolor(GREEN);
				setlinestyle(SOLID_LINE,0,1);
				line(maxx/2,maxy/2,sx,sy);

				// to clear the previous position of minute hand
				mx=maxx/2+mh*cos(omrad);
				my=maxy/2-mh*sin(omrad);
				setcolor(GREEN);
				setlinestyle(SOLID_LINE,0,3);
				line(maxx/2,maxy/2,mx,my);

				// to clear the previous position of hour hand
				hx=maxx/2+hh*cos(ohrad);
				hy=maxy/2-hh*sin(ohrad);
				setcolor(GREEN);
				setlinestyle(SOLID_LINE,0,3);
				line(maxx/2,maxy/2,hx,hy);

				// to erase previous system time
				setcolor(LIGHTBLUE);
				outtextxy(maxx/2-textwidth(ostr)/2,maxy/2+110,ostr);
			}

			// to store previous posion of hand of hour, minute & second
			// and string for system time
			ohrad=hrad;
			omrad=mrad;
			osrad=srad;
			strcpy(ostr,str);

			// to show the system time
			setcolor(RED);
			outtextxy(maxx/2-textwidth(str)/2,maxy/2+110,str);

			// to make internal design
			setcolor(BLACK);
			setlinestyle(SOLID_LINE,0,1);
			setfillstyle(SOLID_FILL,CYAN);
			circle(maxx/2,maxy/2,10);
			floodfill(maxx/2,maxy/2,BLACK);

			// to draw the position of hour hand
			hx=maxx/2+hh*cos(hrad);
			hy=maxy/2-hh*sin(hrad);
			setcolor(BLUE);
			setlinestyle(SOLID_LINE,0,3);
			line(maxx/2,maxy/2,hx,hy);

			// to draw the position of minute hand
			mx=maxx/2+mh*cos(mrad);
			my=maxy/2-mh*sin(mrad);
			setcolor(BROWN);
			setlinestyle(SOLID_LINE,0,3);
			line(maxx/2,maxy/2,mx,my);

			// to draw the position of second hand
			sx=maxx/2+sh*cos(srad);
			sy=maxy/2-sh*sin(srad);
			setcolor(RED);
			setlinestyle(SOLID_LINE,0,1);
			line(maxx/2,maxy/2,sx,sy);

			//to make inter nal design
			setcolor(BLACK);
			setlinestyle(SOLID_LINE,0,1);
			setfillstyle(SOLID_FILL,YELLOW);
			circle(maxx/2,maxy/2,5);
			floodfill(maxx/2,maxy/2,BLACK);

			//to draw central point
			putpixel(maxx/2,maxy/2,BLACK);

			start=1;
			printf("\a");
		}

	}
}