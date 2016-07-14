#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	int i,ln,j;
	char *name;
	clrscr();
	printf("Enter your name please::\n");
	gets(name);
	ln=strlen(name);

	for(i=0;i<ln/2;i++)
	{
		for(j=0;j<ln/2;j++)
		{
			printf(" ");
		}
		printf("%c\n",*(name+i));

	}
	for(i=0;i<ln/2;i++)
	{
		printf("\b");
	}
	puts(name);
	for(i=(ln/2+1);i<=ln;i++)
	{
		for(j=0;j<ln/2;j++)
		{
			printf(" ");
		}
		printf("%c\n",*(name+i));

	}
	getch();
}
