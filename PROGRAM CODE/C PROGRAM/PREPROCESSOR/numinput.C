#include<stdio.h>
#include<conio.h>
#define joy(y) (y>=48&&y<=57)
void main()
{
	char ch;
	clrscr();
	printf("enter any digit");
	scanf("%c",&ch);
	if(joy(ch))
		printf("\n you have entered a digit");
	else
		printf("\n illiegal input");
	getch();
}

