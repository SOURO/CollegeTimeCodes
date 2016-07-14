#include<graphics.h>
void main()
{
	int gd=DETECT,gm,x=10,y,i,j;
	char str[]="Fonts";
	char *demo[]={"Default Fault Demonstration","Triple Font Demonstration",
				  "Small Font Demonstration","Sansserif Font Demonstration",
				  "Gothic Font Demonstration","Script Font Demonstration",
				  "Simplex Font Demonstration","Triplex Font Demonstration",
				  "Complex Font Demonstration","European Font Demonstration",
				  "Bold  Font Demonstration"};

	initgraph(&gd,&gm,"D:\\TC\\BGI");

	setcolor(CYAN);
	for(i=0;i<=10;i++)
	{
		rectangle(0,20,639,479);
		settextstyle(0,0,1);
		outtextxy(150,10,demo[i]);

		y=30;
		for(j=1;j<=4;j++)
		{
			settextstyle(i,HORIZ_DIR,j);
			outtextxy(x,y,str);
			y+=(textheight(str)+10);
			//getch();
		}

		settextstyle(i,VERT_DIR,4);
		setusercharsize(2,1,3,2);
		outtextxy(x,y,str);

		getch();
		clearviewport();
	}
	closegraph();
	restorecrtmode();
}