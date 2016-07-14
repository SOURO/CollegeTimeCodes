/*
-------------------------------------------------------------------------
NAME: Divyen K Patel			Roll No :24					MCA: 4

Translation
-------------------------------------------------------------------------
*/

# include <iostream.h>
# include <conio.h>
# include <graphics.h>
# include <math.h>

char IncFlag;
int PolygonPoints[4][2] =
	{{10,10},{10,100},{100,100},{100,10}};

float Tx=10;
float Ty=10;
void PolyLine()
{
	int iCnt;
	cleardevice();
	line(0,240,640,240);
	line(320,0,320,480);
	for (iCnt=0; iCnt<4; iCnt++)
	{
		line(320+PolygonPoints[iCnt][0],
		     240-PolygonPoints[iCnt][1],
		     320+PolygonPoints[(iCnt+1)%4][0],
		     240-PolygonPoints[(iCnt+1)%4][1]);
	}
}
void Translate()
{
	int iCnt;
	cout<<endl;
	for (iCnt=0; iCnt<4; iCnt++)
	{
		PolygonPoints[iCnt][0] += Tx;
		PolygonPoints[iCnt][1] += Ty;
	}
}

void main()
{
	int gDriver = DETECT, gMode;
	int iCnt;
	initgraph(&gDriver, &gMode, "C:\\TC\\BGI");
	PolyLine();
	getch();
	Translate();
	PolyLine();
	getch();
}
