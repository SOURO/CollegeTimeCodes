#include<stdio.h>
#include<conio.h>
void main()
{
	char str1[25],str2[20];
	int i,j,j1,j2;
	clrscr();
	printf("enter the source string");
	gets(str1);
	printf("enter the sub string");
	gets(str2);
	for(i=0;str1[i]!='\0';i++)
	{
		while(str2[j]!='\0')
		{
			if(str1[i]==str2[j])
			{
				j=j1;
				j++;
			}
			else
			{
				j=j2;
				break;
			}
		}
	}
	if(j==j1)
	{
		printf("match found");
	}
	if(j==j2)
	{
		printf("no match found");
	}
		getch();
}


