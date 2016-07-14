#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t,i,N[1000000][2],j,k,count,l;
    int *status;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&N[i][0]);

    }
    for(i=0;i<t;i++)
    {
        status=(int*)malloc(N[i][0]*sizeof(int));
        for(j=0;j<=N[i][0];j++)
            status[j]=0;
        count=N[i][0];
        for(j=2;j<=N[i][0];j++)
        {
            l=1;
            for(k=j;k<=N[i][0];k=j*l)
            {
                if(status[k]==0)
                {
                    status[k]=1;
                    count--;
                }
                else
                {
                    status[k]=0;
                    count++;
                }
                l++;
            }
        }
        N[i][1]=count;
    }
    for(i=0;i<t;i++)
    {
        printf("\n%d",N[i][1]);
    }
    return 0;
}
