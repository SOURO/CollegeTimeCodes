#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack
{
	int data;
	struct stack *next;
};

typedef struct stack node;
node *top;

void push(int);
void pop();
void search(int);
int count();
void fdisplay();

void main()
{
	int n,num;

	while(1)
	{
		clrscr();
		printf("\t\t\t******   STACK USING LINKLIST   ******\n");
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
					printf("\nENTER A ELEMENT FOR INSERTION\n");
					scanf("%d",&num);
					push(num);
					printf("\n%d IS INSERT AT FIRST PROPERLY\n",num);
					break;
			case 2:
					pop();
					break;
			case 3:
					printf("WHICH ELEMENT YOU WANT TO SEARCH ?\n");
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
	if(!create)
		printf("\nMEMORY ALLOCATION IS NOT POSSIBLE\n");
	else
	{
		create->next=top;
		create->data=num;
		top=create;
	}
}

void pop()
{
	node*temp;
	if(top==NULL)
		printf("\nSTACK IS UNDERFLOW\n");
	else
	{
		temp=top;
		top=top->next;
		printf("\nFIRST NODE IS DELETED PROPERLY WHOSE DATA PART IS %d\n",temp->data);
		free(temp);
	}
}

void search(int num)
{
	node *temp;
	temp=top;
	if(temp==NULL)
		printf("\nSTACK IS UNDERFLOW\n");
	else
	{
		for(temp=top;temp!=NULL&&temp->data!=num;temp=temp->next);
		if(temp==NULL)
			printf("\nSEARCHING ELEMENT %d IS NOT IN THE LIST\n",num);
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
	temp=top;
	if(top==NULL)
		printf("\nSTACK IS UNDERFLOW");
	else
	{
		printf("\nSTACK CONTAIN BELOW ELEMENT::\n\n");
		printf("\t\t\t\t");
		for(temp=top;temp!=NULL;temp=temp->next)
		{
			c++;
			if(c>1)
				printf("--->");
			printf("%d",temp->data);
		}
	}
}









