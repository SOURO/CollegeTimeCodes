#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	int i,j,n,a[30],temp;
	clrscr();
	while(1)
	{
		printf("\n PRESS 1 FOR ASCEDING ORDER");
		printf("\n PRESS 2 FOR DECENDING ORDER ");
		printf("\n PRESS 3 FOR EXIT ");
		printf("\n PRESS THE NUMBER TOU WANT ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("\n HOW MANY NUMBERS YOU WANT ");
				scanf("%d",&n);
				printf("\n ENTER THE NUMBERS ");
				for(i=0;i<n;i++)
				{
					scanf("%d",&a[i]);
				}
				for(i=0;i<=n-1;i++)
				{
					for(j=i+1;j<n;j++)
					{
						if(a[j]<a[i])
						{
							temp=a[j];
							a[j]=a[i];
							a[i]=temp;
						}
					}
				}
				printf("\n THE ASCENDING ORDEER IS :");
				for(i=0;i<n;i++)
				{
					printf("%d " ,a[i]);
				}
				break;
			case 2:
				printf("\n HOW MANY NUMBERS YOU WANT ");
				scanf("%d",&n);
				printf("\n ENTER THE NUMBERS ");
				for(i=0;i<n;i++)
				{
					scanf("%d",&a[i]);
				}
				for(i=0;i<=n-1;i++)
				{
					for(j=i+1;j<n;j++)
					{
						if(a[j]>a[i])
						{
							temp=a[j];
							a[j]=a[i];
							a[i]=temp;
						}
					}
				}
				printf("\n THE DESCENDING ORDER IS:");
				for(i=0;i<n;i++)
				{
					printf("%d ",a[i]);
				}
				break;
			case 3:
				printf("THANK YOU");
				getch();
				exit(0);
		}
	}
}



