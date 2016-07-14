#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 5

int cqueue[SIZE],cnt=0,rear=0,front=0;//GLOBAL VARIBLE

void cqinsertion(int num);//FUNCTION PROTOTYPE
void cdeletion();
void search(int num1);
void fdisp();
void rdisp();


void main()
{

	int n,num,num1;


	while(1)
	{

		clrscr();

		printf("\npress 1 for insert an element on rear\n");
		printf("press 2 for delete an element from front\n");
		printf("press 3 for search an element from list\n");
		printf("press 4 for count the list element\n");
		printf("press 5 for display cqueue element in forward direction\n");
		printf("press 6 for display cqueue element in reverse direction\n");
		printf("press 7 for exit\n\n");
		printf("\nEnter your choice\n");
		scanf("%d",&n);

		switch(n)
		{

			case 1:

				printf("\nEnter an element for cqinsertion:\n");
				scanf("%d",&num);

				cqinsertion(num);

				break;


			case 2:

				cdeletion();

				break;


			case 3:

				printf("Enter which element will be search:\n");
				scanf("%d",&num1);

				search(num1);

				break;


			case 4:
				 printf("\ncqueue contain %d element\n",cnt);
				 break;


			case 5:

				fdisp();

				break;


			case 6:

				rdisp();
				break;


			case 7:

				printf("\nTHANK YOU..\n");
				getch();
				exit(0);

		}
		getch();
	}
}


void cqinsertion(int num)//FUNCTION FOR INSERTION
{
	if(cnt==SIZE)
	{
		printf("\nSORRY..OVER FLOW..\n");
	}
	else
   {
		cqueue[rear]=num;
		rear=(rear+1)%SIZE;
		cnt++;
		printf("\nItem %d is insert properly\n",num);
   }
}


void cdeletion()//FUNCTION FOR DELETION
{
	if(cnt==0)
	{
		printf("SORY..UNDER FLOW\n");
	}
	else
	{

		printf("\nFirst element %d is delete properly\n",cqueue[front]);
		front=(front+1)%SIZE;
		cnt--;
	}
}


void search(int num1)//FUNCTION FOR SEARCHING
{
	int i,flag=0;
	if(cnt==0)
		printf("\nQUEUE IS EMPTY");
	else
	{
		for(i=0;i<cnt;i++)
		{
			if(cqueue[(front+i)%SIZE]==num1)
			{
				flag=1;
				printf("searching element found and it is %dth position\n",i+1);
				break;
			}
		}
		if(flag!=1)
			printf("\nSearching element not found\n");
	}
}


void fdisp()//FUNCTON FOR FORWARD DISPLAY
{
	int i,k;
	if(cnt==0)
		printf("\nQUEUE IS EMPTY\n");
	else
	{
		printf("\nQueue list in forward direction::\n");

		for(i=0;i<cnt;i++)
		{
			printf("\t\t\t\t %2d\n\n",cqueue[(front+i)%SIZE]);
		}
	}
}


void rdisp()//FUNCTION FOR BACKWARD DISPLAY
{
	int i,k;
	if(cnt==0)
	   printf("\nQUEUE IS EMPTY\n");
	else
	{
		printf("\nQueue list in reverse direction::\n");

		for(i=cnt-1;i>=0;i--)
		{
			printf("\t\t\t\t %2d\n\n",cqueue[(front+i)%SIZE]);
		}
	}
}














