/*
-------------------------------------------------------------------------
NAME: Divyen K Patel			Roll No :24					MCA: 4

Midpoint Circle Drawing
-------------------------------------------------------------------------
*/

# include <iostream.h>
# include <conio.h>
# include <graphics.h>
# include <math.h>
void Circle(int Radius,int xC,int yC);
void main()
{
	int gDriver=DETECT, gMode;
	initgraph(&gDriver,&gMode,"c:\\tc\\bgi");

	int Radius, xC, yC;
	cout<< endl << "Enter Center point coordinates...";
	cout<<endl<<"  Xc    : ";
	cin>>xC;
	cout<<endl<<"  Xc    : ";
	cin>>yC;
	cout<<endl<<"Radius  : ";
	cin>>Radius;
	cleardevice();
	Circle(Radius,xC,yC);
	getch();
	return;
}
void Circle(int Radius,int xC,int yC)
{
	int P;
	int x,y;
	void Draw(int x,int y,int xC,int yC);
	P = 1 - Radius;
	x = 0;
	y = Radius;
	Draw(x,y,xC,yC);
	while (x<=y)
	{
		x++;
		if (P<0)
		{
			P += 2 * x + 1;
		}
		else
		{
			P += 2 * (x - y) + 1;
			y--;
		}
		Draw(x,y,xC,yC);
	}

}
void Draw(int x,int y,int xC,int yC)
{
	putpixel(xC + x,yC + y,12);
	putpixel(xC + x,yC - y,12);
	putpixel(xC - x,yC + y,12);
	putpixel(xC - x,yC - y,12);
	putpixel(xC + y,yC + x,12);
	putpixel(xC - y,yC + x,12);
	putpixel(xC + y,yC - x,12);
	putpixel(xC - y,yC - x,12);
}