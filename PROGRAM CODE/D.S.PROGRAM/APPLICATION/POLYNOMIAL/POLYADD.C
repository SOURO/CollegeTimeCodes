#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct polynomial
{
	int coeff;
	int expn;
	struct polynomial *next;
}node;

void poly_insert(int,int,node **);
void poly_display(node **);
void poly_add(node **,node **,node **);

void main()
{
	int n,num1,num2,i;
	node *head1=NULL,*head2=NULL,*head3=NULL;
	char ch;
	clrscr();


	printf("FIRST POLYNOMIAL EXPRESSION ::");
	printf("\n---------------------------\n\n");
	printf("ENTER HOW MANY NO.OF TERM YOU WANT TO GIVE :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nENTER COEFFICIENT AND EXPONENT OF A TERM :");
		scanf("%d",&num1);
		scanf("%d",&num2);
		poly_insert(num1,num2,&head1);
	}
	poly_display(&head1);

	printf("\n\nSECOND POLYNOMIAL EXPRESSION ::");
	printf("\n----------------------------\n\n");
	printf("ENTER HOW MANY NO.OF TERM YOU WANT TO GIVE :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nENTER COEFFICIENT AND EXPONENT OF A TERM :");
		scanf("%d",&num1);
		scanf("%d",&num2);
		poly_insert(num1,num2,&head2);
	}
	poly_display(&head2);

	poly_add(&head1,&head2,&head3);

	printf("\n\nAFTER ADDITION POLYNOMIAL EXPRESSION ::");
	printf("\n------------------------------------");
	poly_display(&head3);

	getch();

}
void poly_insert(int num1,int num2,node **Hpoly)
{

	node *temp,*create;
	if(*Hpoly==NULL)
	{
		create=(node*)malloc(1*sizeof(node));
		create->next=*Hpoly;
		create->coeff=num1;
		create->expn=num2;
		*Hpoly=create;
	}
	else
	{
		create=(node*)malloc(1*sizeof(node));
		for(temp=*Hpoly;temp->next!=NULL;temp=temp->next);
		create->next=NULL;
		temp->next=create;
		create->coeff=num1;
		create->expn=num2;
	}

}

void poly_display(node **Hpoly)
{
	node *temp;
	int flag=0;
	if(*Hpoly==NULL)
		printf("\nLINKLIST IS EMPTY");
	else
	{
		printf("\n\n");
		for(temp=*Hpoly;temp!=NULL;temp=temp->next)
		{
			if(temp->coeff>0 && flag==1)
				printf("+");
			if(temp->coeff==-1)
			{
				if(temp->expn<0)
					printf("-X^(%d)",temp->expn);
				else if(temp->expn==0)
					printf("%d",temp->coeff);
				else if(temp->expn==1)
					printf("-X");
				else
					printf("-X^%d",temp->expn);
			}
			else if(temp->coeff==1)
			{
				if(temp->expn<0)
					printf("X^(%d)",temp->expn);
				else if(temp->expn==0)
					printf("%d",temp->coeff);
				else if(temp->expn==1)
					printf("X");
				else
					printf("X^%d",temp->expn);
			}
			else
			{
				if(temp->expn<0)
					printf("%dX^(%d)",temp->coeff,temp->expn);
				else if(temp->expn==0)
					printf("%d",temp->coeff);
				else if(temp->expn==1)
					printf("%dX",temp->coeff);
				else
					printf("%dX^%d",temp->coeff,temp->expn);
			}

			flag=1;
		}
		printf("\n");
	}
}

void poly_add(node **Hpoly1,node **Hpoly2,node **Hpoly3)
{
	node *temp,*temp1,*temp2;
	temp1=*Hpoly1;
	temp2=*Hpoly2;
	while(temp1!=NULL&&temp2!=NULL)
	{
		if(temp1->expn==temp2->expn)
		{
			if(temp1->coeff+temp2->coeff!=0)
				poly_insert(temp1->coeff+temp2->coeff,temp1->expn,Hpoly3);
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else if(temp1->expn>temp2->expn)
		{
			poly_insert(temp1->coeff,temp1->expn,Hpoly3);
			temp1=temp1->next;
		}
		else
		{
			poly_insert(temp2->coeff,temp2->expn,Hpoly3);
			temp2=temp2->next;
		}
	}
	while(temp1!=NULL)
	{
		poly_insert(temp1->coeff,temp1->expn,Hpoly3);
		temp1=temp1->next;
	}
	while(temp2!=NULL)
	{
		poly_insert(temp2->coeff,temp2->expn,Hpoly3);
		temp2=temp2->next;
	}
}