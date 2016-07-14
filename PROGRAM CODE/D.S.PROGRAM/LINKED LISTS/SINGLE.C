#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct linklist
{
	int data;
	struct linklist *next;
};

typedef struct linklist node;
node *head;

void finsert(int);
void ainsert(int,int);
void binsert(int,int);
void linsert(int);

void fdelete();
void adelete(int);
void bdelete(int);
void edelete(int);
void ldelete();

void search(int);

int count();

void fdisplay();

void reverse();

void main()
{
	int n,num,num1,flag=0;

	while(1)
	{
		clrscr();
		printf("\n\t\t\t******  LINKED LIST OPERATION  ******\n");
		printf("\t\t\t......_________________________......\n");

		printf("\nWELCOME,WHAT YOU WANT TO DO ?::");
		printf("\n_____________________________\n\n");

		printf("\nINSERTION--PRESS 1\n");
		printf("\nDELETION --PRESS 2\n");
		printf("\nSEARCH   --PRESS 3\n");
		printf("\nCOUNT    --PRESS 4\n");
		printf("\nDISPLAY  --PRESS 5\n");
		printf("\nREVERSE  --PRESS 6\n");
		printf("\nEXIT     --PRESS 7\n");
		printf("\n\nENTER YOUR CHOICE::\n");
		scanf("%d",&n);

		switch(n)
		{
			case 1:
					while(1)
					{
						flag=0;
						clrscr();
						printf("INSERT A NODE ::\n");

						printf("\t\tAT FIRST      -PRESS 1.\n");
						printf("\t\tAFTER A NODE  -PRESS 2.\n");
						printf("\t\tBEFORE A NODE -PRESS 3.\n");
						printf("\t\tAT LAST       -PRESS 4.\n");
						printf("\t\tEXIT FROM HERE-PRESS 5.\n");
						printf("\n\nENTER YOUR CHOICE::\n");
						scanf("%d",&n);
						switch(n)
						{
							case 1:
									printf("\nENTER A ELEMENT FOR INSERTION\n");
									scanf("%d",&num);
									finsert(num);
									printf("\n%d IS INSERT AT FIRST PROPERLY\n",num);
									break;
							case 2:
									printf("\nENTER A ELEMENT FOR INSERTION\n");
									scanf("%d",&num);
									printf("AFTER WHICH ELEMENT YOU WANT TO INSERT\n");
									scanf("%d",&num1);
									ainsert(num,num1);
									break;
							case 3:
									printf("ENTER A ELEMENT FOR INSERTION\n");
									scanf("%d",&num);
									printf("BEFORE WHICH ELEMENT YOU WANT TO INSERT\n");
									scanf("%d",&num1);
									binsert(num,num1);
									break;
							case 4:
									printf("ENTER  AN ELEMENT FOR INSERT IN LAST\n");
									scanf("%d",&num);
									linsert(num);
									break;
							case 5:
									printf("\nTHANK YOU FOR USING INSERT OPERETION\n");
									flag=1;
									break;

						}
						getch();
						if(flag==1)
							break;
					}
					break;
			case 2:
					while(1)
					{
						flag=0;
						clrscr();
						printf("DELETE A NODE ::\n");

						printf("\t\tAT FIRST      -PRESS 1.\n");
						printf("\t\tAFTER A NODE  -PRESS 2.\n");
						printf("\t\tBEFORE A NODE -PRESS 3.\n");
						printf("\t\tAT LAST       -PRESS 4.\n");
						printf("\t\tEXACT A NODE  -PRESS 5.\n");
						printf("\t\tEXIT FROM HERE-PRESS 6.\n");
						printf("\n\nENTER YOUR CHOICE::\n");
						scanf("%d",&n);
						switch(n)
						{
							case 1:
									fdelete();
									break;
							case 2:
									printf("\nENTER AFTER WHICH ELEMENT YOU WANT TO DELETE A NODE\n");
									scanf("%d",&num);
									adelete(num);
									break;
							case 3:
									printf("\nENTER BEFORE WHICH ELEMENT YOU WANT TO DELETE A NODE\n");
									scanf("%d",&num);
									bdelete(num);
									break;
							case 4:
									ldelete();
									break;
							case 5:
									printf("WHICH ELEMENT CONTAIN NODE YOU WANT TO DELETE:\n");
									scanf("%d",&num);
									edelete(num);
									break;
							case 6:
									printf("THANK YOU FOR USING DELETE OPERETION");
									flag=1;
									break;
						}
						getch();
						if(flag==1)
							break;
					}
					break;
			case 3:
					printf("WHICH ELEMENT YOU WANT TO SEARCH ?");
					scanf("%d",&num);
					search(num);
					break;
			case 4:
					num=count();
					printf("AT PRESENT LINKLIST CONTAIN %d NODES\n",num);
					break;

			case 5:
					fdisplay();
					break;
			case 6:
					reverse();
					printf("\nREVERSE OPERATION IS COMPLETED SUCESSFULLY\n");
					break;
			case 7:
					printf("\n\nTHANK YOU FOR USING THIS PROGRAM\n");
					getch();
					exit(0);
		}
		getch();
	}
}
void finsert(int num)
{
	node *create;
	create=(node*)malloc(1*sizeof(node));
	if(!create)
		printf("\nMEMORY ALLOCATION IS NOT POSSIBLE\n");
	else
	{
		create->next=head;
		create->data=num;
		head=create;
	}
}
void ainsert(int num,int num1)
{
	node *temp,*create;
	temp=head;
	if(head==NULL)
	{
		printf("THE LIST IS EMPTY");
	}
	else
	{
		for(temp=head;temp!=NULL&&temp->data!=num1;temp=temp->next);
		if(temp==NULL&&temp->data!=num1)
			printf("%d IS NOT IN THE LIST",num1);
		else
		{
			create=(node*)malloc(1*sizeof(node));
			if(!create)
			{
				printf("MEMORY ALLOCATION IS NOT POSSIBLE");
			}
			else
			{
				create->next=temp->next;
				create->data=num;
				temp->next=create;
				printf("\n%d IS INSERT AFTER %d PROPERRLY",num,num1);
			}
		}
	}
}
void binsert(int num,int num1)
{
	node *create,*temp;
	temp=head;
	if(head==NULL)
	{
		printf("\nLINKLIST IS EMPTY");
	}
	else if(head->data==num1)
	{
		create=(node*)malloc(1*sizeof(node));
		if(!create)
		{
			printf("MEMORY ALLOCATION IS NOT POSSIBLE");
		}
		create->next=head;
		create->data=num;
		head=create;
		printf("\n%d IS INSERT BEFORE %d PROPERRLY",num,num1);
	}
	else
	{
		for(temp=head;temp->next!=NULL&&temp->next->data!=num1;temp=temp->next);
		if(temp->next==NULL)
			printf("%d IS NOT IN THE LIST",num1);
		else
		{
			create=(node*)malloc(1*sizeof(node));
			if(!create)
			{
				printf("MEMORY ALLOCATION IS NOT POSSIBLE");
			}
			create->next=temp->next;
			create->data=num;
			temp->next=create;
			printf("\n%d IS INSERT BEFORE %d PROPERRLY",num,num1);
		}
	}
}
void linsert(int num)
{
	node *temp,*create;
	temp=head;
	if(head==NULL)
	{
		create=(node*)malloc(1*sizeof(node));
		if(!create)
			printf("\nMEMORY ALLOCATION IS NOT POSSIBLE\n");
		else
		{
			create->next=head;
			create->data=num;
			head=create;
			printf("\nTHE LINKLIST WAS EMPTY SO INSERTING NODE IS FIRST NODE AS WELL AS LAST NODE\n");
		}
	}
	else
	{
		for(temp=head;temp->next!=NULL;temp=temp->next);

		create=(node*)malloc(1*sizeof(node));

		if(!create)
			printf("MEMORY ALLOCATION IS NOT POSSIBLE");
		else
		{
			create->next=NULL;
			temp->next=create;
			create->data=num;
			printf("\n%d IS INSERT AT LAST PERFECTLY\n",num);
		}
	}

}
void fdelete()
{
	node*temp;
	if(head==NULL)
		printf("\nLINKLIST IS EMPTY\n");
	else
	{
		temp=head;
		head=head->next;
		printf("\nFIRST NODE IS DELETED PROPERLY WHOSE DATA PART IS %d\n",temp->data);
		free(temp);
	}
}
void adelete(int num)
{
	node *temp,*temp1;
	temp=head;
	if(temp==NULL)
		printf("\nLINK LIST IS EMPTY");
	else
	{
		for(temp=head;temp->next!=NULL&&temp->data!=num;temp=temp->next);

		if(temp->next==NULL&&temp->data==num)
			printf("\nNO NODE EXIST AFTER %d\n",num);
		else if(temp->next==NULL)
			printf("%d IS NOT IN THE LIST",num);
		else
		{
			temp1=temp->next;
			temp->next=temp->next->next;
			printf("NODE AFTER %d IS DELETED SUCCESSFULLY WHOSE DATA PART IS %d",temp->data,temp1->data);
			free(temp1);
		}
	}
}
void bdelete(int num)
{
	node *temp,*temp1;
	temp=head;
	if(temp==NULL)
		printf("\nLINK LIST IS EMPTY");
	else if(head->data==num)
		printf("NO NODE EXISTS BEFORE %d",num);
	else if(head->next->data==num)
	{
		printf("1st NODE IS DELETED WHOSE DATA PART IS %d",temp->data);
		head=temp->next;
		free(temp);
	}
	else
	{
		for(temp=head;temp->next->next!=NULL&&temp->next->next->data!=num;temp=temp->next);
		if(temp->next->next==NULL)
			printf("\nSORRY %d IS NOT IN THE LIST\n",num);
		else
		{
			temp1=temp->next;
			temp->next=temp->next->next;
			printf("NODE BEFORE %d IS DELETED SUCCESSFULLY WHOSE DATA PART IS %d",temp->next->data,temp1->data);
			free(temp1);
		}
	}
}
void edelete(int num)
{
	node *temp,*temp1;
	temp=head;
	if(head==NULL)
		printf("\nLINKLIST IS EMPTY\n");
	else if(head->data==num)
	{
		head=temp->next;
		printf("\n1st NODE IS DELETED WHOSE DATA PART IS %d\n",temp->data);
		free(temp);
	}
	else
	{

		for(temp=head;temp->next!=NULL&&temp->next->data!=num;temp=temp->next);
		if(temp->next==NULL)
			printf("%d IS NOT IN THE LIST",num);
		else
		{
			temp1=temp->next;
			temp->next=temp->next->next;
			printf("\nTHE NODE IS DELETED WHOSE DATA PART IS %d",temp1->data);
			free(temp1);
		}
	}
}

void ldelete()
{
	node *temp,*temp1;
	if(head==NULL)
		printf("\nLINKLIST IS EMPTY\n");
	else if(head->next==NULL)
	{
		temp=head;
		head=NULL;
		printf("LAST AS WELL AS FIRST NODE IS DELETED WHOSE DATA PART IS %d",temp->data);
		free(temp);
	}
	else
	{
		for(temp=head;temp->next->next!=NULL;temp=temp->next);
		temp1=temp->next;
		temp->next=NULL;
		printf("\nLAST NODE IS DELETED WHOSE DATA PART IS %d\n",temp1->data);
		free(temp1);
	}
}
void search(int num)
{
	node *temp;
	temp=head;
	if(temp==NULL)
		printf("\nLINKLIST IS EMPTY\n");
	else
	{
		for(temp=head;temp!=NULL&&temp->data!=num;temp=temp->next);
		if(temp==NULL)
			printf("\nSEARCHING ELEMENT IS NOT IN THE LIST\n");
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
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		c++;
	}
	return c;
}

void fdisplay()
{
	int c=0;
	node *temp;
	temp=head;
	if(head==NULL)
		printf("\nLINKLIST IS EMPTY");
	else
	{
		printf("\nLINKLIST CONTAIN BELOW ELEMENT::\n\n");
		printf("\t\t\t\t");
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			c++;
			if(c>1)
				printf("--->");
			printf("%d",temp->data);
		}
	}
}
void reverse()
{
	node *temp1,*temp2,*temp3;
	if(head==NULL)
		printf("LINK LIST IS EMPTY");
	else
	{
		temp1=head;
		temp2=temp1->next;
		temp1->next=NULL;
		while(temp2!=NULL)
		{
			temp3=temp2->next;
			temp2->next=temp1;
			temp1=temp2;
			temp2=temp3;
		}
		head=temp1;
	}
}










