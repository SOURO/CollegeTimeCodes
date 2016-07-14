/*
-------------------------------------------------------------------------
NAME: Divyen K Patel			Roll No :24					MCA: 4

Reflection on any line.
-------------------------------------------------------------------------
*/

# include <iostream.h>
# include <conio.h>
# include <graphics.h>
# include <math.h>

char IncFlag;
int PolygonPoints[3][2] =
	{{10,100},{110,100},{110,200}};

int x1=10;
int y1=10;
int x2=100;
int y2=100;

void PolyLine()
{
	int iCnt;
	cleardevice();
	line(0,240,640,240);
	line(320,0,320,480);
	for (iCnt=0; iCnt<3; iCnt++)
	{
		line(PolygonPoints[iCnt][0],PolygonPoints[iCnt][1],
		  PolygonPoints[(iCnt+1)%3][0],PolygonPoints[(iCnt+1)%3][1]);
	}
}
void Reflect()
{
	float Angle,Slope,Hx,Hy,B;
	int iCnt;
	int Tx,Ty;

	Angle = atan((y2-y1)/(x2-x1));
	Angle *= (M_PI)/180.0;

	Slope = tan(Angle);
	B = y2 - x2*Slope;

	Hx = -B*sin(2.0 * Angle);
	Hy = B*(cos(2.0 * Angle)+1);

	for (iCnt=0; iCnt<3; iCnt++)
	{
		Tx = PolygonPoints[iCnt][0];
		Ty = PolygonPoints[iCnt][1];

		PolygonPoints[iCnt][0] = Tx*cos(2.0*Angle);
			+ Ty*sin(2.0*Angle) + Hx;

		PolygonPoints[iCnt][0] = Tx*sin(2.0*Angle);
			- Ty*cos(2.0*Angle) + Hy;
	}
}

void main()
{
	int gDriver = DETECT, gMode;
	int iCnt;
	initgraph(&gDriver, &gMode, "C:\\TC\\BGI");
	for (iCnt=0; iCnt<3; iCnt++)
	{
		PolygonPoints[iCnt][0] += 320;
		PolygonPoints[iCnt][1] = 240 - PolygonPoints[iCnt][1];
	}
	PolyLine();
	getch();
	Reflect();
	PolyLine();
	getch();
}
