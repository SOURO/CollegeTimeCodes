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
 void inorder(node*,int arr_in[50]);
int i;

int main()
 {
 	node *root;
 	int ch,k,s,d,r,arr_in[50][];
 	printf("enter a data for root");
 	scanf("%d",&r);
    node *newnode;
 	newnode=(node*)malloc(sizeof(node));
 	newnode->lc=NULL;
 	newnode->rc=NULL;
 	newnode->data=r;
 	root=newnode;

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

			case 4:
			 	   inorder(root,arr_in);
			 	   break;
			case 7:
			 	   exit(0);
		}
		printf("\n1.insert:\n2.search:\n3.delete:\n4.inorder:\n5.preorder:\n6.postorder:\n7.exit\n");
		scanf("%d",&ch);
 	}
 	return 0;
 }

void insert(node *ptr ,int y)
{

    node *newnode;
 	newnode=(node*)malloc(sizeof(node));
 	newnode->lc=NULL;
 	newnode->rc=NULL;
 	newnode->data=y;
    node *ptr1=ptr;
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
 {ptr1->lc=newnode;
 }
 else
  {  ptr1->rc=newnode;
   }
}
void inorder(node *ptr,int arr_in[])
{
 node *temp=ptr;
  if(temp==NULL)
   return;

    else{
    inorder(temp->lc);
    printf("%d",temp->data);
    arr_in[i++]=temp->data;
    inorder(temp->rc);}
  //return(temp);
 //}
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

