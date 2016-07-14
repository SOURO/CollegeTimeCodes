#include<graphics.h>
#include<dos.h>
#include<alloc.h>

union REGS i,o;
struct SREGS s;

int c[4][32]={ /*CURSOR 1:hand screen mask*/
					0xe1ff,0xe1ff,0xe1ff,0xe1ff,
					0xe1ff,0x0000,0x0000,0x0000,
					0x0000,0x0000,0x0000,0x0000,
					0x0000,0x0000,0x0000,0x0000,

					0x1e00,0x1200,0x1200,0x1200,
					0x13ff,0x1249,0x1249,0xf249,
					0x9001,0x9001,0x9001,0x8001,
					0x8001,0x8001,0xffff,0x0000,
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
					0x0000,0x0000,0x0000,0x0000,
					0x8001,0xc003,0xf00f,0xfc3f,
					0xfc3f,0xf00f,0xc003,0x8001,
					0x0000,0x0000,0x0000,0x0000,

					0xffff,0x8001,0xffff,0x8001,
					0x4002,0x2004,0x1008,0x0240,
					0x0240,0x0810,0x2004,0x4002,
					0x8001,0xffff,0x8001,0xffff,
			  /*CURSOR 4:para screen mask*/
					0x0000,0x0000,0x0000,0x0000,
					0x0000,0x0000,0x0000,0x0000,
					0x0000,0x0000,0x0000,0x0000,
					0x0000,0x0000,0x0000,0x0000,

					0xffff,0xffff,0xffff,0x0007,
					0x0007,0xeee7,0x0007,0x0007,
					0xeee7,0x0007,0x0007,0xeee7,
					0x0007,0x0007,0xeee7,0xeee7
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

void hidemouseptr()
{
	i.x.ax=1;
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

void disp(int choice,char *p)
{
	getimage((choice-1)*48+1,1,choice*48,32,p);
	putimage((choice-1)*48+1,1,p,NOT_PUT);
}

void main()
{
	int gd=DETECT,gm,button,x,y,area,i,choice;
	char *p;

	initgraph(&gd,&gm,"c:\\tc");

	if(initmouse()==0)
	{
		closegraph();
		printf("\nMouse not installed");exit(1);
	}

	for(i=0;i<4;i++)
	{
		changecursor(c[i]);
		showmouseptr();
		getmousepos(&button,&x,&y);
		area=imagesize(x-15,y-7,x+32,y+24);
		p=malloc(area);
		getimage(x-15,y-7,x+32,y+24,p);
		putimage(i*48+1,1,p,COPY_PUT);
		rectangle(i*48,0,(i+1)*48,33);
		getch();
	}

	gotoxy(10,25);
	printf("Press any key to exit...");

	choice=1;
	disp(choice,p);
	changecursor(c[choice-1]);

	while(!kbhit())
	{
		getmousepos(&button,&x,&y);

		if((button&1)==1)
		{
			for(i=0;i<4;i++)
			{
				if(choice-1==i)
					continue;

				if(y>0 && y<33)
				{
					if(x>i*48 && x<(i+1)*48)
					{
						hidemouseptr();
						disp(choice,p);
						choice=i+1;
						disp(choice,p);
						changecursor(c[choice-1]);
						showmouseptr();
					}
				}
			}
		}
	}
	getch();
	closegraph();
	restorecrtmode();
}