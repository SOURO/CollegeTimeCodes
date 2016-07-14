#include<stdio.h>
#include<conio.h>

int arr[50],flag=0,n=6;
void main()
{
	int i,j;
	void redix();
	clrscr();
   /*	printf("How many element you want to give:\n");
	scanf("%d",n);*/
	printf("\nEnter %d element one by one with two digits:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\nThe first sorted table is:\n");
	printf("-------------------------");
	redix();
	printf("\n\nFirst sorted list:-\n");
	printf("-----------------");
	for(i=0;i<n;i++)
		printf("%3d ",arr[i]);
	flag=2;
	getch();
	printf("\n\nThe final sorted table is:\n");
	printf("-------------------------");
	redix();
	printf("\n\nFinal sorted list:-\n");
	printf("-----------------\n");
	for(i=0;i<n;i++)
		printf("%3d ",arr[i]);
	getch();
}
void redix()
{
	int k1,k2,k3,k4,k5,k6,k7,k8,k9,k0;
	int a,q,p,r;
	int n1,b[10][6];
	k0=k1=k2=k3=k4=k5=k6=k7=k8=k9=a=0;
	while(a<n)
	{
		if(flag==2)
			n1=arr[a]/10;
		else
			n1=arr[a]%10;
		switch(n1)
		{
			case 0:
				b[0][k0++]=arr[a];
				break;
			case 1:
				b[1][k1++]=arr[a];
				break;
			case 2:
				b[2][k2++]=arr[a];
				break;
			case 3:
				b[3][k3++]=arr[a];
				break;
			case 4:
				b[4][k4++]=arr[a];
				break;
			case 5:
				b[5][k5++]=arr[a];
				break;
			case 6:
				b[6][k6++]=arr[a];
				break;
			case 7:
				b[7][k7++]=arr[a];
				break;
			case 8:
				b[8][k8++]=arr[a];
				break;
			case 9:
				b[9][k9++]=arr[a];
				break;
		}
		a++;
	}
	r=0;
	for(p=0;p<10;p++)
	{
		 if(b[p][0]!=0)
			printf("\nBucket %d contain:-",p);
		 for(q=0;q<n;q++)
			if(b[p][q]>0)
			{
				printf("%3d",b[p][q]);
				arr[r++]=b[p][q];
			}
	}
}





