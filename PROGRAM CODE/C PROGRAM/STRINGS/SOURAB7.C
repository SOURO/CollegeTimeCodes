#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	char name[50],name2[50],name3[50];
	int a;
	clrscr();
	printf("enter your name");
	gets(name);
	gets(name2);
       //	puts(name);
      //	puts(name2);
       //	strcat(name,name2);
	a=strcmp(name,name2);
      //	printf("%s %s",name,name2);
		if(a==0)
		{
			printf("two strings are equal");
		}
		else
		{
			printf("two strings are not equal");
		}
	getch();
}