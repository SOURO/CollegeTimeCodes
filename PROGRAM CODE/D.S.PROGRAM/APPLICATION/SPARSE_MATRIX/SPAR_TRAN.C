#include<stdio.h>
#include<conio.h>

typedef struct sparse
{
	int row,col,val;
}sparse;

int m,n;

void sparse_trans(int ,sparse [],sparse []);
void sparse_present(int,sparse []);

void main()
{
	int n1,i,temp;
	sparse s1[50],s3[50];
	clrscr();

	printf("ENTER THE ORDER OF THE MATRIX FOR ADDITION(row X col) :");
	scanf("%d %d",&m,&n);

	printf("\nYOU HAVE TO ENTER FOR 1ST MATRIX::");
	printf("\n----------------------------------");
	printf("\nHOW MANY NON ZREO ELEMENT YOU WANT TO GIVE?:\n");
	scanf("%d",&n1);
	printf("\nENTER ROW INDEX, COLUMN INDEX & VALUE OF %d ELEMENT :\n",n1);
	for(i=0;i<n1;i++)
		scanf("%d %d %d",&s1[i].row,&s1[i].col,&s1[i].val);

	printf("\nYOU HAVE TO ENTER FOR 1ST MATRIX ::\n");
	sparse_present(n1,s1);

	sparse_trans(n1,s1,s3);

	temp=m;
	m=n;
	n=temp;
	printf("\nAFTER TRANSPOSE, MATRIX ::\n");
	sparse_present(n1,s3);

	getch();
}

void sparse_trans(int n1,sparse s1[],sparse s3[])
{
	int i;

	for(i=0;i<n1;i++)
	{
		s3[i].row=s1[i].col;
		s3[i].col=s1[i].row;
		s3[i].val=s1[i].val;
	}
}

void sparse_present(int noe,sparse s[])
{
	int i,j,cnt=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==s[cnt].row && j==s[cnt].col && cnt<noe)
			{
				printf("%3d ",s[cnt++].val);
			}
			else
				printf("  0 ");
		}
		printf("\n");
	}
}