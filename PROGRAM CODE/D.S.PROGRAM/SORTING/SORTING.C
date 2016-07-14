#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void bubble(int,int arr[]);
void selection(int,int arr[]);
void insertion(int,int arr[]);
void quick(int arr[],int,int,int);
void mergesort(int arr[],int,int);
void merge(int arr[],int,int,int);

void main()
{
	int n,i,arr[50],temp[50],ch;
	while(1)
	{
		clrscr();
		printf("\npress 1 for bubble sort\n");
		printf("press 2 for selection sort\n");
		printf("press 3 for insertion sort\n");
		printf("press 4 for quick sort\n");
		printf("press 5 for merge sort\n");
		printf("press 6 for exit\n");
		printf("\n\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("How many number you want to give:\n");
				scanf("%d",&n);
				printf("enter number one by one:\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&arr[i]);
				}

				bubble(n,arr);
				break;

			case 2:
				printf("\nHow many number you want to give\n");
				scanf("%d",&n);
				printf("\nEnter number one by one\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&arr[i]);
				}

				selection(n,arr);
				break;

			case 3:
				printf("\nHow many number you want to give:\n");
				scanf("%d",&n);
				printf("\nEnter number one by one\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&arr[i]);
				}

				insertion(n,arr);
				break;

			case 4:
				printf("\nHow many number you want to give:\n");
				scanf("%d",&n);
				printf("\nEnter number one by one\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&arr[i]);
				}
				quick(arr,0,n-1,n);
				break;

			case 5:
				printf("\nHow many number you want to give:\n");
				scanf("%d",&n);
				printf("\nEnter number one by one\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&arr[i]);
				}
				mergesort(arr,0,n-1);
				break;

			case 6:
				printf("Thank you");
				getch();
				exit(0);
		}

		printf("\n\nThe sorted order is : " );
		for(i=0;i<n;i++)
		{
			printf("%d ",arr[i]);
		}
		getch();
	}
}

void bubble(int n,int arr[])
{
	int i,j,temp,k;
	for(i=0;i<n-1;i++)
	{

		for(j=n-1;j>i;j--)
		{

			if(arr[j]<arr[j-1])
			{
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
		}
/*		printf("\nIteretion no %d:: ",i+1);
		for(k=0;k<n;k++)
		{
			printf("%d ",arr[k]);
		}	*/
	}
}

void selection(int n,int arr[])
{
	int i,j,min,temp,k;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<=n-1;j++)
		{
			if(arr[min]>arr[j])
			{
			  min=j;
			}

		}
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;

/*		printf("\nIteretion no %d:: ",i+1);
		for(k=0;k<n;k++)
		{
			printf("%d ",arr[k]);
		}	*/
	}
}

void insertion(int n,int arr[])
{
	int i,j,k,temp;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=0&&temp<arr[j];j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=temp;

/*		printf("\nIteretion no %d:: ",i+1);
		for(k=0;k<n;k++)
		{
			printf("%d ",arr[k]);
		}	*/
	}
}

void quick(int arr[],int first,int last,int n)	// ACTUALLY n IS NOT REQUIRED TO PASS IN THE ALGO, JUST FOR EACH ITTERATION ONLY
{
	int l=first,h=last,pivot=arr[(l+h)/2],temp,j,k;
	static int i;
	while(l<=h)
	{
		while(arr[l]<pivot)
			l++;
		while(arr[h]>pivot)
			h--;
		if(l<=h)
		{
			temp=arr[l];
			arr[l]=arr[h];
			arr[h]=temp;
			l++;
			h--;
		}
		i++;
		printf("\n\n\t%d <-> %d",arr[l-1],arr[h+1]);
		printf("\nIteretion no %d (key %d):",i,pivot);
		for(k=0;k<n;k++)
		{
			printf("%d ",arr[k]);
		}
	}
	if(first<h)
		quick(arr,first,h,n);
	if(l<last)
		quick(arr,l,last,n);
}

void mergesort(int arr[],int l,int r)
{
	int mid=(r+l)/2;

	if(r>l)
	{
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid+1,r);
	}
}

void merge(int arr[],int l,int mid,int r)
{
	int i,leftend,pos,noe,temp[50];

	leftend=mid-1;
	pos=l;
	noe=r-l+1;
	while(l<=leftend && mid<=r)
	{
		if(arr[l]<=arr[mid])
		{
			temp[pos]=arr[l];
			pos++;
			l++;
		}
		else
		{
			temp[pos]=arr[mid];
			pos++;
			mid++;
		}
	}
	while(l<=leftend)
	{
		temp[pos]=arr[l];
		pos++;
		l++;
	}
	while(mid<=r)
	{
		temp[pos]=arr[mid];
		pos++;
		mid++;
	}

	for(i=0;i<=noe;i++)
	{
		arr[r]=temp[r];
		r--;
	}
}