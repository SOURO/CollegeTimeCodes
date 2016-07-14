#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,m,matrix[10][10],max,max1,min,row,colm;
    printf("Enter the order(row colmn) of the matrix\n");
    scanf("%d %d",&n,&m);
    printf("Enter the number one one by one row wise\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        min=matrix[i][0];
        colm=1;
        for(j=0;j<m;j++)
        {
            if(min>matrix[i][j])
            {
                min=matrix[i][j];
                colm=j+1;
            }
        }
        if(i==0)
        {
            max=min;
            row=i+1;
        }
        else if(min>max)
        {
            max=min;
            row=i+1;
        }
    }
    for(j=0;j<m;j++)
    {
        max1=matrix[j][0];
        for(i=0;i<n;i++)
        {
            if(max1<matrix[i][j])
            {
                max1=matrix[i][j];
            }
        }
        if(j==0)
        {
            min=max1;
        }
        else if(max1<min)
        {
            min=max1;
        }
    }
    if(max==min)
    {
        printf("Saddle point is (position(%d,%d))::%d",row,colm,max);
    }
    else
    {
        printf("No saddle point exist in the given matrix!!");
    }

    return 0;
}
