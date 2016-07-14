#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 100


int stack[SIZE],top=0;//GLOBAL VARIBLE

void push(int num);//FUNCTION PROTOTYPE
void pop();
void search(int num1);
void fdisp();
void rdisp();


void main()
{

	int n,num,num1;


	while(1)
	{

		clrscr();

		printf("\npress 1 for insert an element on top\n");
		printf("press 2 for delete an element from top\n");
		printf("press 3 for search an element from list\n");
		printf("press 4 for count the list element\n");
		printf("press 5 for display list element in forward direction\n");
		printf("press 6 for display list element in reverse direction\n");
		printf("press 7 for exit\n\n");
		printf("\nEnter your choice\n");
		scanf("%d",&n);

		switch(n)
		{
			case 1:
				printf("\nEnter an element for insertion:\n");
				scanf("%d",&num);
				push(num);
				break;


			case 2:
				pop();
				break;


			case 3:
				printf("Enter which element will be search:\n");
				scanf("%d",&num1);
				search(num1);
				break;


			case 4:
				 printf("\nstack contain %d element\n",top);
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


void push(int num)//FUNCTION FOR INSERTION
{
	if(top==SIZE)
	{
		printf("\nSORRY..OVER FLOW..\n");
	}
	else
   {
		stack[top++]=num;
		printf("\nItem %d is insert properly\n",stack[top-1]);
   }
}


void pop()//FUNCTION FOR DELETION
{
	if(top==0)
	{
		printf("SORY..UNDER FLOW\n");
	}
	else
	{

		top--;
		printf("\nTop element %d is delete properly\n",stack[top]);
	}
}


void search(int num1)//FUNCTION FOR SEARCHING
{
	int i,flag=0;
	if(top==0)
		printf("\nSTACK IS EMPTY\n");
	else
	{

		for(i=0;i<top;i++)
		{
			if(stack[i]==num1)
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
	int i;
	if(top==0)
		printf("STACK IS EMPTY");
	else
	{
		printf("\nStack list in forward direction::\n");

		for(i=top-1;i>=0;i--)
		{
			printf("\t\t\t\t %d\n\n",stack[i]);
		}
	}
}


void rdisp()//FUNCTION FOR BACKWARD DISPLAY
{
	int i;
	if(top==0)
		printf("STACK IS EMPTY");
	else
	{
		printf("\nStack list in reverse direction::\n");

		for(i=0;i<top;i++)
		{
			printf("\t\t\t\t %d\n\n",stack[i]);
		}
	}
}














