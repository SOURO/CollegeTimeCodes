#include<stdio.h>
#include<stdlib.h>

 struct BST
 {
 	struct BST *lc;
 	int data;
 	struct BST *rc;
 };
 typedef struct BST node;
 node* createnode();
 void insert(node*,int);
 void search(node*,int);
 void deletenode(node*,int);
 void inorder(node*);
 void preorder(node*);
 void postorder(node*);


int main()
 {
 	int ch,k,s,d,r;
 	printf("enter a data for root");
 	scanf("%d",&r);
        node *root=createnode();
        root->data=r;
 	printf("\n1.insert:\n2.search:\n3.delete:\n4.inorder:\n5.preorder:\n6.postorder:\n7.exit\n");
 	scanf("%d",&ch);
 	while(1)
 	{
 		switch(ch)
 		{
 			case 1:
 				   printf("\n enter a data to insert");
 				   scanf("%d",&k);
 				   insert(root,k);
 				   break;
 			case 2:
			 	   printf(" \n enter the no to be inserted");
			 	   scanf("%d",s);
			 	   search(root,s);
			 	   break;
			case 3:
			 	   printf("\n enter the data to delete");
			 	   scanf("%d",&d);
			 	   deletenode(root,d);
			 	   break;
			case 4:
			 	   inorder(root,d);
			 	   break;
			case 5:
			 	   preorder(root);
			 	   break;
			case 6:
			 	   postorder(root);
			 	   break;
                        default :
			           printf("Invalid");
			case 7:
			 	   exit(0);
		}
		printf("\n1.insert:\n2.search:\n3.delete:\n4.inorder:\n5.preorder:\n6.postorder:\n7.exit\n");
		scanf("%d",&ch);
 	}
 	return 0;
 }

 node* createnode()
 {
 	node *newnode;
 	newnode=(node*)malloc(sizeof(node));
 	newnode->lc=NULL;
 	newnode->rc=NULL;
 	return(newnode);
}

void insert(node *ptr ,int y)
{
 node *ptr1;
 while(ptr!=NULL)
 {
  ptr1=ptr;
  if(y>ptr->data)
  {ptr=ptr->rc;
  }
  else
  {ptr=ptr->lc;
  }
 }
 if(ptr1->data>y)
 {ptr1->lc=createnode();
  ptr1->lc->data=y;
 }
 else
  {  ptr1->rc=createnode();
     ptr1->rc->data=y;
   }
}

void search(node *ptr,int s)
{int flag=0;
 if(ptr=NULL)
 {flag=0;
 }
 else
{
	while(ptr!=NULL)
	{
		if(s>ptr->data)
		{ptr=ptr->rc;
	   	}
	   	else if(s<ptr->data)
	   	{ptr=ptr->lc;
	   	}
	   	else if(s==ptr->data)
	   	{flag=1;
	   	}
	   	else
	   	{flag=0;
	   	}
	}

}
if(flag==1)
printf("search successful");
else
printf("search unsuccessful");

}

void deletenode(node *ptr,int d)
{
	node *parent;
while(ptr!=NULL)
{parent=ptr;
if(d>ptr->data)
{ptr=ptr->rc;
}
else
{ptr=ptr->lc;
}
}
if(ptr==NULL)
{printf("deletion is not possible");
}
else
{if(ptr->lc==NULL&&ptr->rc==NULL)
 {if(ptr==parent->lc)
  {parent->lc=NULL;
  }
  else
  {parent->rc=NULL;
  }
  free(ptr);
 }
 else if(ptr->lc!=NULL)
 {if(ptr==parent->lc)
  {parent->lc=ptr->lc;
  }
  else
  {parent->rc=ptr->lc;
  }
 }
 else if(ptr->rc!=NULL)
 {if(ptr=parent->lc)
  {parent->lc=ptr->rc;
  }
  else
  {parent->rc=ptr->rc;
  }
 }
 else if(ptr->lc!=NULL&&ptr->rc!=NULL)
 {node *q;
  q=inorder(ptr,d);
  delete(q);
  ptr=q;
 }
}
}

void inorder(node *ptr,int b)
{
 node *temp=ptr;
 while(temp!=NULL)
 //{//while(temp->data!=b)
  {temp=temp->lc;
   printf("%d",temp->data);
   temp=temp->rc;
  }
  //return(temp);
 //}
}
void preorder(node *ptr)
{node *temp=ptr;
 if(temp!=NULL)
 {printf("%d",temp->data);
  preorder(ptr->lc);
  preorder(ptr->rc);
 }
 else
 return ;
}
void postorder(node *ptr)
{node *temp=ptr;
 if(temp!=NULL)
 {postorder(ptr->lc);
  postorder(ptr->rc);
  printf("%d",temp->data);
 }
 else
 return ;
}
