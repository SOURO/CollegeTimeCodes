#include<stdio.h>
#include<conio.h>

typedef struct sparse
{
	int row,col,val;
}sparse;

int m,n;

int sparse_add(int ,sparse [],int ,sparse [],sparse []);
void sparse_present(int,sparse []);

void main()
{
	int n1,n2,i,noe;
	sparse s1[50],s2[50],s3[50];
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

	printf("\nYOU HAVE TO ENTER FOR 2ND MATRIX::");
	printf("\n----------------------------------");
	printf("\nHOW MANY NON ZREO ELEMENT YOU WANT TO GIVE?:\n");
	scanf("%d",&n2);

	printf("\nENTER ROW INDEX, COLUMN INDEX & VALUE OF %d ELEMENT :\n",n2);
	for(i=0;i<n2;i++)
		scanf("%d %d %d",&s2[i].row,&s2[i].col,&s2[i].val);

	printf("\nYOU HAVE TO ENTER FOR 2ND MATRIX ::\n");
	sparse_present(n2,s2);

	noe=sparse_add(n1,s1,n2,s2,s3);

	printf("\nAFTER ADDITION, MATRIX ::\n");
	sparse_present(noe,s3);

	getch();
}
int sparse_add(int n1,sparse s1[],int n2,sparse s2[],sparse s3[])
{
	int i=0,j=0,k=0;
	while(i!=n1&&j!=n2)
	{
		if(s1[i].row==s2[j].row)
		{
			if(s1[i].col==s2[j].col)
			{
				s3[k].val=s1[i].val+s2[j].val;
				s3[k].row=s1[i].row;
				s3[k].col=s1[i].col;
				i++;
				j++;
				k++;
			}
			else if(s1[i].col>s2[j].col)
			{
				s3[k].val=s2[j].val;
				s3[k].row=s2[j].row;
				s3[k].col=s2[j].col;
				k++;
				j++;
			}
			else
			{
				s3[k].val=s1[i].val;
				s3[k].row=s1[i].row;
				s3[k].col=s1[i].col;
				i++;
				k++;
			}
		}
		else if(s1[i].row>s2[i].row)
		{
			s3[k].val=s2[j].val;
			s3[k].row=s2[j].row;
			s3[k].col=s2[j].col;
			k++;
			j++;
		}
		else
		{
			s3[k].val=s1[i].val;
			s3[k].row=s1[i].row;
			s3[k].col=s1[i].col;
			i++;
			k++;
		}
	}
	while(i!=n1)
	{
		s3[k].val=s1[i].val;
		s3[k].row=s1[i].row;
		s3[k].col=s1[i].col;
		i++;
		k++;
	}
	while(j!=n2)
	{
		s3[k].val=s2[j].val;
		s3[k].row=s2[j].row;
		s3[k].col=s2[j].col;
		j++;
		k++;
	}
	return k;
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