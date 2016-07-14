#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
	char temp[10],name[8][20]={"Shivshakti",
								"Shubhodeep",
								"Bhedprakash",
								"Ram",
								"Ravi",
								"Gourab",
								"Prasun",
								"Soumen"
								};
	int n=8,i,j,l;

	clrscr();


	for(i=0;i<n-1;i++)
	{

		for(j=i+1;j<n;j++)
		{
			if(strcmp(name[i],name[j])>0)
			{
				strcpy(temp,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],temp);
			}

		}
	}

	printf("\nThe right order of your name list is::\n\n");

	for(i=0;i<n;i++)
	{
		printf("  %s\n",name[i]);
	}
	getch();
}