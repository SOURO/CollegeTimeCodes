/*
-------------------------------------------------------------------------
NAME: Divyen K Patel			Roll No :24					MCA: 4

Scaling about Reference Point
-------------------------------------------------------------------------
*/

# include <iostream.h>
# include <conio.h>
# include <graphics.h>
# include <math.h>

char IncFlag;
int PolygonPoints[4][2] =
	{{10,10},{10,100},{100,100},{100,10}};

float Sx=0.5;
float Sy=2.0;

int RefX=55;
int RefY=55;
void PolyLine()
{
	int iCnt;
	cleardevice();
	line(0,240,640,240);
	line(320,0,320,480);
	for (iCnt=0; iCnt<4; iCnt++)
	{
		line(320+PolygonPoints[iCnt][0],240-PolygonPoints[iCnt][1],
		  320+PolygonPoints[(iCnt+1)%4][0],240-PolygonPoints[(iCnt+1)%4][1]);
	}
}

void Scale()
{
	int iCnt;
	int Tx,Ty;
	cout<<endl;
	for (iCnt=0; iCnt<4; iCnt++)
	{
		PolygonPoints[iCnt][0] *= Sx;
		PolygonPoints[iCnt][0] += (1-Sx)*RefX;
		PolygonPoints[iCnt][1] *= Sy;
		PolygonPoints[iCnt][1] += (1-Sy)*RefY;
	}
}

void main()
{
	int gDriver = DETECT, gMode;
	int iCnt;
	initgraph(&gDriver, &gMode, "C:\\TC\\BGI");
	PolyLine();
	getch();
	Scale();
	PolyLine();
	getch();
}
