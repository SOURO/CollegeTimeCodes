#include<stdio.h>
#include<conio.h>
int year(int);
int month(int);
void day(int);
void main()
{
	int y,m,d1,date,yt,m1,y1,yr=0,i,yg,y2;
	clrscr();
	while(1)
	{
		printf("\nenter the year(>=1901) ");
		scanf("%d",&y);
		if(y<1901)
			printf("\ninvalid year");
		else
			break;
	}
	while(1)
	{
		printf("\nenter the month(e.g:enter 7 for july) ");
		scanf("%d",&m);
		if(m>12)
			printf("\ninvalid month!");
		else
			break;
	}
	y1=year(y);
	m1=month(m);
	while(1)
	{
		printf("\nenter the date ");
		scanf("%d",&date);
		if(y1==0)
		{
			if(m1==0)
			{
				if(date>31)
					printf("\ninvalid date!");
				else
					break;
			}
			else if(m1==1)
			{
				if(date>29)
					printf("\ninvalid date!");
				else
					break;
			}
			else
			{
					if(date>30)
					printf("\ninvalid date!");
				else
					break;
			}
		}
		if(y1==1)
		{
			if(m1==0)
			{
				if(date>31)
					printf("\ninvalid date!");
				else
					break;
			}
			else if(m1==1)
			{
				if(date>28)
					printf("\ninvalid date!");
				else
					break;
			}
			else
			{
				if(date>30)
					printf("\ninvalid date!");
				else
					break;
			}
		}
	}
	for(i=1900;i<=y;i++)
	{
		if(i%4==0&&i%100!=0||i%400==0)
		{
			yr=yr+1;
		}
	}
	yg=y-1900+1;
	y2=year(y);
	if(y2==0)
	{
		yt=yg+yr-1;
		for(i=1;i<m;i++)
		{
			if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
				yt=yt+31;
			else if(i==2)
				yt=yt+29;
			else
				yt=yt+30;
		}
	}
	if(y2==1)
	{
		yt=yg+yr;
		for(i=1;i<m;i++)
		{
			if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
				yt=yt+31;
			else if(i==2)
				yt=yt+28;
			else
				yt=yt+30;
		}
	}
	d1=yt+date;
	day(d1);
	getch();
}
int year(int y)
{
	if(y%4==0&&y%100!=0||y%400==0)
		return(0);
	else
		return(1);
}
int month(int m)
{
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		return(0);
	else if(m==2)
		return(1);
	else
		return(2);
}
void day(int d1)
{
	if(d1%7==1)
	       printf("\n THE DAY IS SUNDAY");
	else if(d1%7==2)
		printf("\n THE DAY IS MONDAY");
	else if(d1%7==3)
		printf("\n THE DAY IS TUESDAY");
	else if(d1%7==4)
		printf("\n THE DAY IS WEDNESDAY");
	else if(d1%7==5)
		printf("\n THE DAY IS THURSDAY");
	else if(d1%7==6)
		printf("\n THE DAY IS FRIDAY");
	else
		printf("\n THE DAY IS SATURDAY");
}

