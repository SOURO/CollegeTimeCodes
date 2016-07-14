/*		Heap Sort	*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>

void heap(int);

int arr[50]={21,4,8,16,7,1,5,19,12,15,13,18,3,24,9};

void main()
{
	int i,n;
	int temp;
	void heapify(int);
	clrscr();

	printf("Heap Sort");
	/*printf("Enter How many Numbers : ");
	scanf("%d",&n);*/
	n=15;

	/*printf("ENTER %d DATA :",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);*/

	for(i=n-1;i>0;i--)
	{
		heap(i);
		temp =  arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
	}

	printf("Resultant Array :");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

	getch();
}

void heap(int n)
{
	int i,temp;
	for(i=(n-1)/2;i>=0;i--)
	{
		if(arr[(2*i)+1] < arr[(2*i)+2] && (2*i+2)<=n)
		{
			temp = arr[(2*i)+1];
			arr[(2*i)+1] = arr[(2*i)+2];
			arr[(2*i)+2] = temp;
		}
		if(arr[(2*i)+1] > arr[i] && (2*i+1)<=n)
		{
			temp = arr[(2*i)+1];
			arr[(2*i)+1] = arr[i];
			arr[i] = temp;
		}
	}
}