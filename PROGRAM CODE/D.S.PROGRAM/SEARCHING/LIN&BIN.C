#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void linear(int,int,int arr[]);
void binary(int,int,int arr[]);

void main()
{
	int n,n1,arr[50],i;
	while(1)
	{
		clrscr();
		printf("\npress 1 for linear search\n");
		printf("press 2 for binary search\n");
		printf("press 3 for exit\n");

		printf("\n\nEnter your choice\n");
		scanf("%d",&n);

		switch(n)
		{
			case 1:
					printf("How many number you want to give:\n");
					scanf("%d",&n);
					printf("Enter numbers one by one:\n");
					for(i=0;i<n;i++)
					{
						scanf("%d",&arr[i]);
					}
					printf("Enter which number you want to find out:\n");
					scanf("%d",&n1);

					linear(n,n1,arr);

					break;
			case 2:
					printf("\nHow many number you want to give?:\n");
					scanf("%d",&n);
					printf("\nEnter number one by one in ascending order:\n");
					for(i=0;i<n;i++)
					{
						scanf("%d",&arr[i]);
					}
					printf("\nWhich number you want to find out?\n");
					scanf("%d",&n1);

					binary(n,n1,arr);

					break;
			case 3:

					printf("\nTHANK YOU\n");
					getch();
					exit(0);
		}
		getch();
	}
}
void linear(int n,int n1,int arr[])
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]==n1)
		{
			flag=1;
			printf("The number is found and it is %dth position\n",i+1);

			break;
		}
	}
	if(flag!=1)
	{
		printf("The number is not found\n");
	}
}
void binary(int n,int n1,int arr[])
{
	int first=0,last=n-1,mid,flag=0;

	while(first<=last)
	{
		mid=(first+last)/2;
		if(n1==arr[mid])
		{
			flag=1;
			printf("\nThe number is found and it is %dth position\n",mid+1);
			break;
		}
		else if(n1>arr[mid])
		{
			first=mid+1;
		}
		else
		{
			last=mid-1;
		}
	}
	if(flag!=1)
	{
		printf("\nThe number is not found\n");
	}
}




