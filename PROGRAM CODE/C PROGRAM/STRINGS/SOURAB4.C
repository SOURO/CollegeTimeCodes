#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	char name[50],name2[50];
	int n;
	clrscr();
	printf("enter your name");
	gets(name);
      //	puts(name);
	n=strlen(name);
	strcpy(name2,name);
	puts(name2);
	printf("the length of the given charecter is %d",n);
	getch();
}