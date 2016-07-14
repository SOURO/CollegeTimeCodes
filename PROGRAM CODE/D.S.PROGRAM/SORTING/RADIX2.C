#define NUMELTS 100
#include<stdio.h>
#include<conio.h>
#include<math.h>

void radixsort(int a[],int);

void main()
{
	int n=15,a[20]={21,4,8,16,7,1,5,19,12,15,13,18,3,24,9},i;
	clrscr();

	/*printf("enter the number :");
	scanf("%d",&n);
	printf("ENTER %d DATA :",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]); */

	radixsort(a,n);
	getch();
}
void radixsort(int a[],int n)
{
	int rear[10],front[10],first,p,q,exp,k,i,y,j;
	struct
	{
		int info;
		int next;
	}node[NUMELTS];

	for(i=0;i<n-1;i++)
	{
		node[i].info=a[i];
		node[i].next=i+1;
	}
	node[n-1].info=a[n-1];
	node[n-1].next=-1;
	first=0;

	for(k=1;k<=2;k++)      //consider only 2 digit number
	{
		for(i=0;i<10;i++)
		{
			front[i]=-1;
			rear[i]=-1;
		}

		while(first!=-1)
		{
			p=first;
			first=node[first].next;
			y=node[p].info;
			exp=pow(10,k-1);
			j=(y/exp)%10;
			q=rear[j];
			if(q==-1)
				front[j]=p;
			else
				node[q].next=p;
			rear[j]=p;
		}
		for(j=0;j<10&&front[j]==-1;j++);

		first=front[j];
		while(j<=9)
		{
			for(i=j+1;i<10&&front[i]==-1;i++);
			if(i<=9)
			{
				p=i;
				node[rear[j]].next=front[i];
			}
			j=i;
		}
		node[rear[p]].next=-1;
	}
	//copy into original array
	for(i=0;i<n;i++)
	{
		a[i]=node[first].info;
		first=node[first].next;

	}

	printf("\n\nDATA AFTER RADIX SORTING :\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}