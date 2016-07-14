/*
-------------------------------------------------------------------------
NAME: Divyen K Patel			Roll No :24					MCA: 4

Liang Barsky Algorithm for Line Clipping
-------------------------------------------------------------------------
*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
#include<math.h>

#define false 0
#define true  1

FILE *fin = fopen("cosuth.in","r");
float u1,u2,dx,dy;
float t1,t2,t3,t4,t5,t6;

class point
{
     int x,y;
     int code[4];
public:
	void getxy()
	{
		fscanf(fin,"%d %d",&x,&y);
	}
	void putxy(int x1,int y1)
	{
		x = x1;
		y = y1;
	}
	void friend clipline(point p1,point p2);
	int friend cliptest(float p,float q,float *u1,float *u2);
	void friend drawline(point p1,point p2);

}p1,p2,pt[20],winmin,winmax;

void clipline(point p1,point p2)
{
	rectangle(80,420,426,160);

	u1 = 0.0;
	u2 = 1.0;

	dx = p2.x - p1.x;
	t1 = p1.x - winmin.x;
	t2 = winmax.x - p1.x;
	t3 = p1.y - winmin.y;
	t4 = winmax.y - p1.y;
	t5 = -1 * dx;


	if (cliptest(t5,t1,&u1,&u2) == 1)
	{
		if (cliptest(dx,t2,&u1,&u2) == 1)
		{
			dy = float(p2.y - p1.y);
			t6 = -1 * dy;
			if (cliptest(t6,t3,&u1,&u2) == 1)
			{
				if (cliptest(dy,t4,&u1,&u2) == 1)
				{
					if (u1 > 0.0)
					{
						(int)p1.x = p1.x + (u1 * dx);
						(int)p1.y = p1.y + (u1 * dy);
					}
					if (u2 < 1.0)
					{
						(int)p2.x = p1.x + (u2 * dx);
						(int)p2.y = p1.y + (u2 * dy);
					}
				}
			}
		}
	}
	drawline(p1,p2);
	getch();
}

int cliptest(float p,float q,float *u1,float *u2)
{
	float r;
	int flag;

	flag = 1;

	if (p < 0.0)
	{
		r = (float) q / p;
		if (r > *u2)
		{
			flag = 0;
		}
		else
		{
			if (r > *u1)
			{
				*u1 = r;
			}
		}
	}
	else
	{
		if (p > 0.0)
		{
			r = (float) q / p;
			if (r < *u1)
			{
				flag = 0;
			}
			else
			{
				if (r < *u2)
				{
					*u2 = r;
				}
			}
		}
		else
		{
			if (q < 0.0)
			{
				flag = 0;
			}
		}
	}
	return(flag);
}

void drawline(point p1,point p2)
{
     line(p1.x,p1.y,p2.x,p2.y);
}


void main()
{
	int drv=DETECT,mode,totalpoint,i;

	clrscr();

	printf("\nHow many line will be on the screen : ");
	fscanf(fin,"%d",&totalpoint);

	for(i = 0;i < totalpoint ; i++)
	{
		printf("\nEnter their x and y coordinates of %d point:\n",i+1);
		pt[i].getxy();
	}

	initgraph(&drv,&mode,"c:\\Borlandc\\bgi");
	winmin.putxy(80,160);
	winmax.putxy(420,426);
	rectangle(80,420,426,160);

	i = 0;

	do
	{
		drawline(pt[i],pt[i+1]);
		i++;
	}
	while(i < totalpoint-1);

	getch();
	clearviewport();

	i = 0;
	do
	{
		clipline(pt[i],pt[i+1]);
		i++;
	}
	while(i < totalpoint-1);
	getch();
}
