#include<stdio.h>
#include<conio.h>

void fucking();
void sucking();

#pragma startup fucking
#pragma exit sucking

void main()
{
	printf("\nYou are a main boy");
	getch();
}
void fucking()
{
	clrscr();
	printf("\nYou are a fucking boy");
	getch();
}
void sucking()
{
	printf("\nYou are a sucking boy");
	getch();
}