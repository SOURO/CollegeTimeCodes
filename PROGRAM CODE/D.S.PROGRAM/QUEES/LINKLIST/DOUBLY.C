#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct linklist
{
	struct linklist *prev;
	int data;
	struct linklist *next;
};

typedef struct linklist node;
node *front,*rear;

void linsert(int);
void fdelete();
void search(int);
int count();
void fdisplay();
void rdisplay();

void main()
{
	int n,num;

	while(1)
	{
		clrscr();
		printf("\n\t\t****** QUEUE USING DOUBLY LINKED LIST ******\n");
		printf("\t\t......______________________________......\n");

		printf("\nWELCOME,WHAT YOU WANT TO DO ?::");
		printf("\n_____________________________\n\n");

		printf("\nINSERTION   --PRESS 1\n");
		printf("\nDELETION    --PRESS 2\n");
		printf("\nSEARCH      --PRESS 3\n");
		printf("\nCOUNT       --PRESS 4\n");
		printf("\nDISPLAY(F)  --PRESS 5\n");
		printf("\nDISPLAY(R)  --PRESS 6\n");
		printf("\nEXIT        --PRESS 7\n");
		printf("\n\nENTER YOUR CHOICE::\n");
		scanf("%d",&n);

		switch(n)
		{
			case 1:
					printf("ENTER  AN ELEMENT FOR INSERT IN LAST\n");
					scanf("%d",&num);
					linsert(num);
					break;

			case 2:
					fdelete();
					break;

			case 3:
					printf("WHICH ELEMENT YOU WANT TO SEARCH ?\n");
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
					rdisplay();
					break;
			case 7:
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
	temp=front;
	if(front==NULL)
	{
		create=(node*)malloc(1*sizeof(node));
		if(!create)
			printf("\nMEMORY ALLOCATION IS NOT POSSIBLE\n");
		else
		{
			create->next=front;
			create->data=num;
			front=create;
			rear=create;
			printf("\n%d IS INSERT AT REAR PERFECTLY\n",num);
		}
	}
	else
	{
		create=(node*)malloc(1*sizeof(node));

		if(!create)
			printf("MEMORY ALLOCATION IS NOT POSSIBLE");
		else
		{
			create->prev=rear;
			create->next=NULL;
			rear->next=create;
			create->data=num;
			rear=create;
			printf("\n%d IS INSERT AT REAR PERFECTLY\n",num);
		}
	}

}
void fdelete()
{
	node*temp;
	if(front==NULL)
		printf("\nQUEUE IS EMPTY\n");
	else
	{
		temp=front;
		front=front->next;
		if(temp->next!=NULL)
			temp->next->prev=NULL;
		printf("\nFIRST NODE IS DELETED PROPERLY WHOSE DATA PART IS %d\n",temp->data);
		free(temp);
	}
}
void search(int num)
{
	node *temp;
	temp=front;
	if(temp==NULL)
		printf("\nQUEUE IS EMPTY\n");
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
		printf("\nQUEUE IS EMPTY");
	else
	{
		printf("\nQUEUE CONTAIN BELOW ELEMENT(FORWARD)::\n\n");
		printf("\t\t\t\t\t ");
		for(temp=front;temp!=NULL;temp=temp->next)
		{
			c++;
			if(c>1)
			{
				printf(" <---> ");

			}
			printf("%d",temp->data);
		}
	}
}
void rdisplay()
{
	int c=0;
	node *temp;
	if(front==NULL)
		printf("\nQUEUE IS EMPTY");
	else
	{
		printf("\nQUEUE CONTAIN BELOW ELEMENT(BACKWARD)::\n\n");
		printf("\t\t\t\t\t ");
		for(temp=rear;temp!=NULL;temp=temp->prev)
		{
			c++;
			if(c>1)
			{
				printf(" <---> ");
			}
			printf("%d",temp->data);
		}
	}
}











