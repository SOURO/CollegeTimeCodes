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
node *top,*tail;

void push(int);
void pop();
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
		printf("\n\t\t****** STACK USING DOUBLY LINK LIST ******\n");
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
					printf("\nENTER A ELEMENT FOR INSERTION\n");
					scanf("%d",&num);
					push(num);
					printf("\n%d IS INSERT AT TOP PROPERLY\n",num);
					break;
			case 2:
					pop();
					break;
			case 3:
					printf("WHICH ELEMENT YOU WANT TO SEARCH ?/n");
					scanf("%d",&num);
					search(num);
					break;
			case 4:
					num=count();
					printf("AT PRESENT STACK CONTAIN %d NODES\n",num);
					break;

			case 5:
					fdisplay();
					break;
			case 6:
					rdisplay();
					break;
			case 7:
					printf("\n\nTHANK YOU FOR USING STACK PROGRAM\n");
					getch();
					exit(0);
		}
		getch();
	}
}
void push(int num)
{
	node *create;
	create=(node*)malloc(1*sizeof(node));
	if(top==NULL)
	{
		if(!create)
			printf("\nMEMORY ALLOCATION IS NOT POSSIBLE\n");
		else
		{
			create->prev=NULL;
			create->next=NULL;
			create->data=num;
			top=create;
			tail=create;
		}
	}
	else
	{
		if(!create)
			printf("\nMEMORY ALLOCATION IS NOT POSSIBLE\n");
		else
		{
			create->prev=NULL;
			create->next=top;
			create->data=num;
			top->prev=create;
			top=create;
		}
	}
}
void pop()
{
	node*temp;
	if(top==NULL)
		printf("\nSTACK IS EMPTY\n");
	else
	{
		temp=top;
		top=top->next;
		if(temp->next!=NULL)
			temp->next->prev=NULL;
		printf("\nFIRST NODE IS DELETED PROPERLY WHOSE DATA PART IS %d\n",temp->data);
		free(temp);
	}

}
void search(int num)
{
	node *temp;
	if(top==NULL)
		printf("\nSTACK IS EMPTY\n");
	else
	{
		for(temp=top;temp!=NULL&&temp->data!=num;temp=temp->next);
		if(temp==NULL)
			printf("\nSEARCHING ELEMENT IS NOT IN THE STACK\n");
		else
		{
			printf("\nSEARCHING ELEMENT %d IS FOUND\n",num);
		}
	}
}

int count()
{
	int c=0;
	node *temp;
	for(temp=top;temp!=NULL;temp=temp->next)
	{
		c++;
	}
	return c;
}

void fdisplay()
{
	int c=0;
	node *temp;
	if(top==NULL)
		printf("\nSTACK IS EMPTY");
	else
	{
		printf("\nSTACK CONTAIN BELOW ELEMENT(FORWARD)::\n\n");
		printf("\t\t\t\t\t ");
		for(temp=top;temp!=NULL;temp=temp->next)
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
	node *temp,*temp1;
	if(top==NULL)
		printf("\nSTACK IS EMPTY");
	else
	{
		printf("\nSTACK CONTAIN BELOW ELEMENT(BACKWARD)::\n\n");
		printf("\t\t\t\t\t ");
		for(temp=tail;temp!=NULL;temp=temp->prev)
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











