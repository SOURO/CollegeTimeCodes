#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
	char name[40];
	int l,i,j;


	clrscr();

	printf("\nEnter your name please::\n   ");
	gets(name);

	l=strlen(name);

	printf("\n\nyour modified name style is:\n\n");
	printf("   %c",toupper(name[0]));


	for(i=1;i<l;i++)//i starts from 1,bcz we alwys print first char.
	{
		if(name[i]==' ')
		{
			printf(".%c",toupper(name[++i]));

			for(j=i+1;j<l;j++)
			{
				if(name[j]==' ')
				{
					break;
				}
			}
			if(j==l)
			{
				for(j=i+1;j<l;j++)
				{
					printf("%c",name[j]);
				}
			}

		}
		else
		{
			continue;
		}
	}
	getch();
}
