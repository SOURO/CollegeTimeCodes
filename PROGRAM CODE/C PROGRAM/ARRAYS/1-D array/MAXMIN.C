#include<stdio.h>
#include<conio.h>
void main()
{
	int num[10],i,n,max,min;
	clrscr();
	printf("HOW MANY NUMBERS YOU WANT TO GIVE ");
	scanf("%d",&n);
	printf("ENTER THE NUMBERS ONE BY ONE ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	max=0;
	min=0;
	for(i=0;i<n;i++)
	{
		if(num[max]<num[i])
		{
			max=i;
		}
		if(num[min]>num[i])
		{
			min=i;
		}
	}
	printf("MAX=%d",num[max]);
	printf("\n IT IS %dth ELEMENT",max+1);
	printf("\n MIN=%d",num[min]);
	printf("\n IT IS %dth ELEMENT",min+1);
	getch();
}

