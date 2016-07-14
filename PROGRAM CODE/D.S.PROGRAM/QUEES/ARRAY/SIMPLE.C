#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 100

int queue[SIZE],rear=0,front=0;//GLOBAL VARIBLE

void insertion(int num);//FUNCTION PROTOTYPE
void deletion();
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
		printf("press 5 for display queue element in forward direction\n");
		printf("press 6 for display queue element in reverse direction\n");
		printf("press 7 for exit\n\n");
		printf("\nEnter your choice\n");
		scanf("%d",&n);

		switch(n)
		{

			case 1:

				printf("\nEnter an element for insertion:\n");
				scanf("%d",&num);

				insertion(num);

				break;


			case 2:

				deletion();

				break;


			case 3:

				printf("Enter which element will be search:\n");
				scanf("%d",&num1);

				search(num1);

				break;


			case 4:
				 printf("\nQueue contain %d element\n",rear);
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


void insertion(int num)//FUNCTION FOR INSERTION
{
	if(rear==SIZE)
	{
		printf("\nSORRY..OVER FLOW..\n");
	}
	else
   {
		queue[rear++]=num;
		printf("\nItem %d is insert properly\n",queue[rear-1]);
   }
}


void deletion()//FUNCTION FOR DELETION
{
	if(front==rear)
	{
		printf("SORY..UNDER FLOW\n");
	}
	else
	{

		printf("\nFirst element %d is delete properly\n",queue[front]);
		front++;
	}
}


void search(int num1)//FUNCTION FOR SEARCHING
{
	int i,flag=0;
	if(front==rear)
		printf("\nQUEUE IS EMPTY");
	else
	{
		for(i=front;i<rear;i++)
		{
			if(queue[i]==num1)
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
	if(front==rear)
		printf("\nQUEUE IS EMPTY\n");
	else
	{
		printf("\nQueue list in forward direction::\n");

		for(i=front;i<rear;i++)
		{
			printf("\t\t\t\t %2d\n\n",queue[i]);
		}
	}
}


void rdisp()//FUNCTION FOR BACKWARD DISPLAY
{
	int i,k;
	if(front==rear)
	   printf("\nQUEUE IS EMPTY\n");
	else
	{
		printf("\nQueue list in reverse direction::\n");

		for(i=rear-1;i>=front;i--)
		{
			printf("\t\t\t\t %2d\n\n",queue[i]);
		}
	}
}














