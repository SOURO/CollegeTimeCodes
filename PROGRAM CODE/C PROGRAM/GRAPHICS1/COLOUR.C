#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	int i;
	clrscr();
	for(i=1;i<=14;i++)
	{
		textbackground(i);
		textcolor(i+1);
		cprintf("SOURA IS GENIOUS\n\r");
	}
	getch();
}
