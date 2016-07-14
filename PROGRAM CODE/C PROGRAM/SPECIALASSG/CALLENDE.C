#include<stdio.h>
#include<conio.h>

int grt_input();
int year(int);
int month(int,int);
int date(int);

void main()
{
	int y,yr,mn,s,m,d,dt;
	clrscr();

	printf("Enter the date(DD:MM:YYYY)::\n");
	scanf("%d %d %d",&d,&m,&y);

	yr=year(y);
	mn=month(m,y);
	dt=date(d);

	s=(yr+mn+dt)%7;


	switch(s)
	{
		case 0:
				printf("monday");
				break;
		case 1:
				printf("tuesday");
				break;
		case 2:
				printf("wednesday");
				break;
		case 3:
				printf("thrusday");
				break;
		case 4:
				printf("friday");
				break;
		case 5:
				printf("saturday");
				break;
		case 6:
				printf("sunday");
	}
	getch();
}

int year(int y)
{
  int count=0,i,yr;


	for(i=1;i<y;i++)
	{
		if(i%100!=0&&i%4==0||i%400==0)
		{
			count++;
		}
	}

	yr=(y-1)+count;
	yr=yr%7;

	return yr;
}


int month(int m,int y)
{
	int s=0,i;
	for(i=1;i<=m;i++)
	{

		switch(i)
		{
			case 1:
					s=0;
					break;
			case 2:
			case 4:
			case 6:
			case 8:
			case 9:
			case 11:
					s=s+31;
					break;
			case 3:
					s=s+28;
					break;
			case 5:
			case 7:
			case 10:
			case 12:
					s=s+30;

		}
	}

	if((y%100!=0&&y%4==0||y%400==0)&&m!=1&&m!=2)
	{
		s=s+1;
	}

	s=s%7;
	return s;
}
int date(int d)
{
	d=(d-1)%7;
	return d;
}


