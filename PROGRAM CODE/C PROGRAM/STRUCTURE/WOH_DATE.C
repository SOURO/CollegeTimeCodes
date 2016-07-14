#include<stdio.h>
#include<conio.h>
struct DATE
{
	int dd;
	int mm;
	int yy;
}d;
void main()
{
	clrscr();
	printf("ENTER a DATE (date: dd-mm-yy) :\n");
	scanf("date: %d-%d-%d",&d.dd,&d.mm,&d.yy);
	printf("date: %02d-%02d-%04d",d.dd,d.mm,d.yy);
	getch();
}