#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,m,n,m1,n1,**matrix1,**matrix2,**matrix3;
    printf("Enter the order of first matrix:\n");
    scanf("%d %d",&m,&n);
    printf("Enter the value row wise::\n");
    matrix1=(int**)malloc(m*sizeof(int*));
    if(!matrix1)
    {
        printf("Memory allocation operation is not successful!!\n");
        return 1;
    }
    for(i=0;i<m;i++)
    {
        matrix1[i]=(int*)malloc(n*sizeof(int));
        if(!matrix1[i])
        {
            printf("Memory allocation operation is not successful!!\n");
            return 1;
        }
        for(j=0;j<n;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("Enter the order of second matrix:\n");
    scanf("%d %d",&m1,&n1);
    printf("Enter the value row wise::\n");
    matrix2=(int**)malloc(m1*sizeof(int*));
    if(!matrix2)
    {
        printf("Memory allocation operation is not successful!!\n");
        return 1;
    }
    for(i=0;i<m1;i++)
    {
        matrix2[i]=(int*)malloc(n1*sizeof(int));
        if(!matrix2[i])
        {
            printf("Memory allocation operation is not successful!!\n");
            return 1;
        }
        for(j=0;j<n1;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }
    matrix3=(int**)malloc(m*sizeof(int*));
    if(!matrix3)
    {
        printf("Memory allocation operation is not successful!!\n");
        return 1;
    }
    for(i=0;i<m;i++)
    {
        matrix3[i]=(int*)malloc(n1*sizeof(int));
        if(!matrix3[i])
        {
            printf("Memory allocation operation is not successful!!\n");
            return 1;
        }
    }
    printf("\nThe resultant matrix is as follows::-\n\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n1;j++)
        {
            matrix3[i][j]=0;
            for(k=0;k<m1;k++)
            {
                matrix3[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
            printf("%4d ",matrix3[i][j]);
        }
        printf("\n");
    }
    free(matrix1);
    free(matrix2);
    free(matrix3);
    return 0;
}
