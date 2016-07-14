#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()

{
	int i,j,k,ln;
	char src_str[50],trg_str[20];

	clrscr();

	printf("Enter the source string\n");
	gets(src_str);
	printf("Enter the target string\n");
	gets(trg_str);

	ln=strlen(src_str);

	for(i=0;i<ln;i++)
	{

		k=i;
		j=0;

		while(*(src_str+k)==*(trg_str+j)&&*(trg_str+j)!='\0')
		{
			k++;
			j++;
		}

		if(*(trg_str+j)=='\0')
		{
			printf("\nSEARCH STRING FOUND\n");
			printf("THE TARGET STRING STARTS FROM THE (FROM LEFT) %dTH POSITION",i+1);
			break;

		}
	}

	if(*(trg_str+j)!='\0')
	{
		printf("\nSEARCH STRING NOT FOUND\n");

	}

	getch();
}
