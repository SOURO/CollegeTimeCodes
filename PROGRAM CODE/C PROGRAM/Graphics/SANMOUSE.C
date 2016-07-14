#include<graphics.h>
#include<conIO.h>
#include<dos.h>

union REGS i,o;
struct SREGS s;

int cursor[32]={
				 /*CURSOR 1:hand screen mask*/
				/*	0xe1ff,0xe1ff,0xe1ff,0xe1ff,
					0xe1ff,0x0000,0x0000,0x0000,
					0x0000,0x0000,0x0000,0x0000,
					0x0000,0x0000,0x0000,0x0000,

					0x1e00,0x1200,0x1200,0x1200,
					0x13ff,0x1249,0x1249,0xf249,
					0x9001,0x9001,0x9001,0x8001,
					0x8001,0x8001,0xffff,0x0000,     */
			  /*CURSOR 2:arrow screen mask*/
					0xffff,0xffff,0xe003,0xf003,
					0xf803,0xfc03,0xfe03,0xfc03,
					0xf803,0xf043,0xe0e3,0xc1f3,
					0x83fb,0x07ff,0x8fff,0xdfff,

					0x0000,0x0000,0x1ffc,0x0804,
					0x0404,0x0204,0x0104,0x0204,
					0x0444,0x08a4,0x1114,0x220c,
					0x4404,0x8800,0x5000,0x2000,
			  /*CURSOR 3:hour-glass screen mask*/
			   /*		0x0000,0x0000,0x0000,0x0000,
					0x8001,0xc003,0xf00f,0xfc3f,
					0xfc3f,0xf00f,0xc003,0x8001,
					0x0000,0x0000,0x0000,0x0000,

					0xffff,0x8001,0xffff,0x8001,
					0x4002,0x2004,0x1008,0x0240,
					0x0240,0x0810,0x2004,0x4002,
					0x8001,0xffff,0x8001,0xffff,       */
			  /*CURSOR 4:para screen mask*/
				/*	0x0000,0x0000,0x0000,0x0000,
					0x0000,0x0000,0x0000,0x0000,
					0x0000,0x0000,0x0000,0x0000,
					0x0000,0x0000,0x0000,0x0000,

					0xffff,0xffff,0xffff,0x0007,
					0x0007,0xeee7,0x0007,0x0007,
					0xeee7,0x0007,0x0007,0xeee7,
					0x0007,0x0007,0xeee7,0xeee7      */
	};

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

void changecursor(int *shape)
{
	i.x.ax=9;
	i.x.bx=0;
	i.x.cx=0;
	i.x.dx=(unsigned)shape;
	segread(&s);
	s.es=s.ds;
	int86x(0x33,&i,&o,&s);
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
	int gd=DETECT,gm,maxx,maxy,x,y,button;

	initgraph(&gd,&gm,"c:\\tc");
	window(1,1,80,25);
	maxx=getmaxx();
	maxy=getmaxy();

	//window(1,1,80,25);

	rectangle(300,400,350,450);
	setviewport(1,57,maxx-1,maxy-1,1);

	if(initmouse()==0)
	{
		closegraph();
		restorecrtmode();
		printf("\nMouseDriver not loaded");
		exit(0);
	}

	gotoxy(26,1);
	printf("MOUSE DEMONSTRATION PROGRAM");

	restrictmouseptr(1,57,maxx-1,maxy-1);
	showmouseptr();

	gotoxy(1,2);
	printf("Left Button");

	gotoxy(15,2);
	printf("Right Button");

	gotoxy(55,3);
	printf("Press Any Key to Exit...");

	while(!kbhit())
	{
		getmousepos(&button,&x,&y);
	while(x>300 && x<350 && y>400 && y<450)
	{
		getmousepos(&button,&x,&y);

		gotoxy(5,3);
		(button & 1)==1? printf("DOWN") : printf("UP  ");

		gotoxy(20,3);
		(button & 2)==2? printf("DOWN") : printf("UP  ");

		gotoxy(65,2);
		printf("x=%03d y=%03d",x,y);
	}
	}
	gotoxy(10,1);
	printf("Press Any Key To Exit...");

	changecursor(cursor);
	showmouseptr();
	getch();
}