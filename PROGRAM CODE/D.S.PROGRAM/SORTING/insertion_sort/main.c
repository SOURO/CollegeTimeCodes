#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,num,arr[20],swap=0,temp=0;
    printf("Enter How many number you want to give?\n");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=1;i<num;i++)
    {
        temp=i;
        for(j=i-1;j>=0 && arr[j]>arr[temp];j--)
        {
            swap=arr[j];
            arr[j]=arr[temp];
            arr[temp]=swap;
            temp--;
        }
    }
    printf("\n");
    for(i=0;i<num;i++)
    {
        printf("%d  ",arr[i]);
    }
    return 0;
}
