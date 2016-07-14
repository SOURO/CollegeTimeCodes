#include<sydio.h>
#include<conio.h>
#include<string.h>
void main()
{
	char str1[25],str2[20];
	int i,j;
	clrscr();
	printf("enter the source string");
	gets(str1);
	printf("enter the sub string");
	gets(str2);
	l1=strlen(str1);
	l2=strlen(str2);
	for(i=0;i<l2;i++);
	{
		while(str1[j]!='\0')
		{
			if(str2[i]== str1[j])
			{
				i