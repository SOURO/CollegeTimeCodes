#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	char *str1,*str2,*str3;
	int i,j,l1,l2;
	clrscr();

	/*		strlen(str)		*/
	printf(":: PROGRAM OF strlen(str) ::\n\n");
	printf("Enter any string :");
	gets(str1);

	l1=strlen(str1);
	printf("\nUSING strlen(str), lenth of the string :%d",l1);

	for(l1=0;*(str1+l1)!='\0';l1++);
	printf("\n\nNOT USING strlen(str), lenth of the string :%d",l1);


	/*		strcpy(str_dest,str_src)		*/
	printf(":: PROGRAM OF strcpy(str_dest,str_src) ::\n\n");
	printf("Enter any string :");
	gets(str1);

	strcpy(str2,str1);
	printf("\nUSING strcpy(str_dest,str_src), the string :");
	puts(str2);

	for(l1=0;*(str1+l1)!='\0';l1++);
	for(i=0;i<=l1-1;i++)
	{
		*(str2+i)=*(str1+i);
	}
	*(str2+i)='\0';
	printf("\nNOT USING strcpy(str_dest,str_src), the string :");
	puts(str2);


	/*		strrev(str)		*/
	printf(":: PROGRAM OF strrev(str) ::\n\n");
	printf("Enter any string :");
	gets(str1);

	strrev(str1);
	printf("\nUSING strrev(str), the string :");
	puts(str1);

	for(l1=0;*(str1+l1)!='\0';l1++);
	for(i=0;i<=l1-1;i++)
	{
		*(str2+i)=*(str1+l1-1-i);
	}
	*(str2+i)='\0';
	printf("\nNOT USING strrev(str), the string :");
	puts(str2);


	/*		strcat(str_dest,str_src)		*/
	printf(":: PROGRAM OF strcat(str_dest,str_src) ::\n\n");
	printf("Enter any string :");
	gets(str1);
	printf("Enter another string :");
	gets(str2);

	strcat(str1,str2);
	printf("\nUSING strcat(str_dest,str_src), the string :");
	puts(str1);

	for(l1=0;*(str1+l1)!='\0';l1++);
	for(l2=0;*(str2+l2)!='\0';l2++);
	for(i=0;i<=l1-1;i++)
	{
		*(str3+i)=*(str1+i);
	}
	for(j=0;j<=l2-1;j++)
	{
		*(str3+i+j)=*(str2+j);
	}
	*(str3+j+i)='\0';
	printf("\nNOT USING strcat(str_dest,str_src), the string :");
	puts(str3);


	/*		strcmp(str1,str2)		*/
	printf(":: PROGRAM OF strcmp(str1,str2) ::\n\n");
	printf("Enter any string :");
	gets(str1);
	printf("Enter another string :");
	gets(str2);

	printf("\nUSING strcmp(str1,str2)\n");
	i=strcmp(str1,str2);
	if(i==0)
		printf("the string is SIMILAR\n\n");
	else
		printf("the string is NOT SIMILAR\n\n");

	printf("\nNOT USING strcmp(str1,str2)\n");
	for(l1=0;*(str1+l1)!='\0';l1++);
	for(l2=0;*(str2+l2)!='\0';l2++);
	if(l1!=l2)
	{
		printf("the string is NOT SIMILAR");
	}
	else
	{
		for(i=0;i<=l1-1;i++)
		{
			if(*(str1+i)!=*(str2+i))
			{
				printf("the string is NOT SIMILAR");
				break;
			}
		}
		if(i>=l1)
			printf("the string is SIMILAR");
	}


	/*		palindrome		*/
	printf(":: PROGRAM OF PALINDROME ::\n\n");
	printf("Enter any string :");
	gets(str1);

	for(l1=0;*(str1+l1)!='\0';l1++);
	for(i=0;i<=l1/2;i++)
	{
		if(*(str1+i)!=*(str1+l1-i-1))
		{
			printf("the string is NOT PALINDROME");
			break;
		}
	}
	if(i>l1/2)
		printf("the string is PALINDROME");

	getch();
}