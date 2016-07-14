#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<time.h>

#define space 40

void multiply(char[],char[],int,int);
void presentation(char[],char[],int,int);

int mul[50][50],sum[50],arr[50],len[50],l,k,i3,n;

void main()
{

	char num1[50],num2[50];
	int l1,l2;
	time_t first, second;

	clrscr();

	textcolor(6);
	cprintf("\nENTER A NUMBER::\n\r");
	gets(num1);

	textcolor(6);
	cprintf("\nENTER ANOTHER NUMBER::\n\r");
	gets(num2);

	first = time(NULL);

	l1=strlen(num1);
	l2=strlen(num2);

	if(l1<l2)
		multiply(num2,num1,l2,l1);	 //FUNCTION CALL FOR MULTIPLICATION
	else
		multiply(num1,num2,l1,l2);

	if(l1<l2)
		presentation(num2,num1,l2,l1); //FUNCTION CALL FOR PRESENTATION
	else
		presentation(num1,num2,l1,l2);

	second = time(NULL);
	printf("\n\n\t\t\t");
	printf("THIS OPERATION TAKES : %f seconds\n\n\t\t\t",difftime(second,first));

	textcolor(14+128);
	cprintf("YOUR OPERATION HAVE DONE SUCESSFULLY...\r");

	getch();
}

void multiply(char num1[],char num2[],int l1,int l2)   //FUNCTION FOR MULTIPLICATION
{
	int i,j,n1,n2,c,m,s,i1,i2;

	l=0;
	for(i=l2-1;i>=0;i--)   //PROCESS FOR INNER MULTIPLICATION
	{
		n2=num2[i]-48;
		k=0;
		if(n2==0)
		{
			len[l]=l1;	// BY DEFAULT ALL ELEMENTS ARE 0
		}
		else if(n2==1)
		{
			for(j=l1-1;j>=0;j--)
			{
				n1=num1[j]-48;
				mul[l][k++]=n1;
				len[l]++;
			}
		}
		else
		{
			c=0;
			for(j=l1-1;j>=0;j--)
			{
				n1=num1[j]-48;
				s=(n1*n2)+c;
				len[l]++;
				if(s>=10)
				{
					mul[l][k++]=s%10;
					c=s/10;
				}
				else
				{
					mul[l][k++]=s;
					c=0;
				}
			}
			if(c>0)
			{
				mul[l][k++]=c;
				len[l]++;
			}
		}
		l++;
		arr[n++]=k;

	}

	c=0;
	i3=0;
	for(i=0;i<(k+l)-1;i++)  //PROCESS FOR ADDITION
	{
		i2=i;
		s=0;
		i1=0;
		for(j=0;j<i+1;j++)
		{
			s=s+mul[i1][i2];
			i1++;
			i2--;

		}
		if((s+c)>=10)
		{
			sum[i3++]=(s+c)%10;
			c=(s+c)/10;
		}
		else
		{
			sum[i3++]=(s+c);
			c=0;
		}
		len[l]++;
	}
	if(c>0)
	{
		sum[i3++]=c;
		len[l]++;
	}
}

void presentation(char num1[],char num2[],int l1,int l2)  //FUNCTION FOR PRESENTATION
{
	int i,j;

	textcolor(4);
	printf("\n\n\t\t\t");
	cprintf("*****::MULTIPLICATION RESULT::*****\n\r");

	printf("\t\t\t");
	textcolor(2+128);
	cprintf("-----------------------------------\n\n\n\r");

	printf("\t\t\t\t\t");
	puts(num1);

	printf("\n");

	printf("\t\t\t\t     *  ");
	if(l1!=l2)
	{
		for(i=1;i<=l1-l2;i++)
			printf(" ");
		puts(num2);
	}
	else
	{
		puts(num2);
	}

	printf("\n\t\t\t");
	textcolor(2+128);
	cprintf("-----------------------------------\n\n\r");

	for(i=0;i<l;i++)
	{
		for(j=0;j<space-i-(len[i]-l1);j++)
			printf(" ");

		for(j=len[i]-1;j>=0;j--)
		{
			printf("%d",mul[i][j]);
		}

		for(j=0;j<i;j++)
		{
			textcolor(2);
			cprintf("x");
		}
		printf("\n\n");
	}

	printf("\t\t\t");
	textcolor(2+128);
	cprintf("-----------------------------------\n\r");

	for(j=0;j<space-(len[l]-l1);j++)
		printf(" ");

	for(j=i3-1;j>=0;j--)
		printf("%d",sum[j]);
}