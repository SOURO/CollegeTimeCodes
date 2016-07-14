#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct queue
{
	int data;
	struct queue *next;
};

typedef struct queue node;
node *front,*rear;

void linsert(int);
void fdelete();
void search(int);
int count();
void fdisplay();

void main()
{
	int n,num,num1;

	while(1)
	{
		clrscr();
		printf("\n\t\t\t******  QUEUE USING LINKLIST  ******\n");
		printf("\t\t\t......_________________________......\n");

		printf("\nWELCOME,WHAT YOU WANT TO DO ?::");
		printf("\n_____________________________\n\n");

		printf("\nINSERTION   --PRESS 1\n");
		printf("\nDELETION    --PRESS 2\n");
		printf("\nSEARCH      --PRESS 3\n");
		printf("\nCOUNT       --PRESS 4\n");
		printf("\nDISPLAY(F)  --PRESS 5\n");
		printf("\nEXIT        --PRESS 6\n");
		printf("\n\nENTER YOUR CHOICE::\n");
		scanf("%d",&n);

		switch(n)
		{
			case 1:
					printf("ENTER  AN ELEMENT FOR INSERTION\n");
					scanf("%d",&num);
					linsert(num);
					break;

			case 2:
					fdelete();
					break;

			case 3:
					printf("WHICH ELEMENT YOU WANT TO SEARCH ?");
					scanf("%d",&num);
					search(num);
					break;
			case 4:
					num=count();
					printf("AT PRESENT QUEUE CONTAIN %d NODES\n",num);
					break;

			case 5:
					fdisplay();
					break;
			case 6:
					printf("\n\nTHANK YOU FOR USING QUEUE PROGRAM\n");
					getch();
					exit(0);
		}
		getch();
	}
}

void linsert(int num)
{
	node *temp,*create;
	if(front==NULL)
	{
		create=(node*)malloc(1*sizeof(node));
		if(!create)
			printf("\nMEMORY ALLOCATION IS NOT POSSIBLE\n");
		else
		{
			create->next=NULL;
			create->data=num;
			front=create;
			rear=create;
			printf("\n%d IS INSERT AT FIRST IN QUEUE PROPERLY\n",num);
		}
	}
	else
	{
		create=(node*)malloc(1*sizeof(node));
		if(!create)
			printf("MEMORY ALLOCATION IS NOT POSSIBLE");
		else
		{
			create->next=NULL;
			rear->next=create;
			create->data=num;
			rear=create;
			printf("\n%d IS INSERT AT LAST PERFECTLY\n",num);
		}
	}
}
void fdelete()
{
	node*temp;
	if(front==NULL)
		printf("\nQUEUE IS UNDERFLOW\n");
	else
	{
		temp=front;
		front=front->next;
		printf("\nFIRST NODE IS DELETED PROPERLY WHOSE DATA PART IS %d\n",temp->data);
		free(temp);
	}
}

void search(int num)
{
	node *temp;
	temp=front;
	if(temp==NULL)
		printf("\nQUEUE IS UNDERFLOW\n");
	else
	{
		for(temp=front;temp!=NULL&&temp->data!=num;temp=temp->next);
		if(temp==NULL)
			printf("\nSEARCHING ELEMENT IS NOT IN THE QUEUE\n");
		else
		{
			printf("SEARCHING ELEMENT %d IS FOUND",num);
		}
	}
}

int count()
{
	int c=0;
	node *temp;
	for(temp=front;temp!=NULL;temp=temp->next)
	{
		c++;
	}
	return c;
}

void fdisplay()
{
	int c=0;
	node *temp;
	if(front==NULL)
		printf("\nQUEUE IS UNDERFLOW");
	else
	{
		printf("\nQUEUE CONTAIN BELOW ELEMENT::\n\n");
		printf("\t\t\t\t");
		for(temp=front;temp!=NULL;temp=temp->next)
		{
			c++;
			if(c>1)
				printf("--->");
			printf("%d",temp->data);
		}
	}
}









