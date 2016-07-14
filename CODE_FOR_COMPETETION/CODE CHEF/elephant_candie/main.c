#include <stdio.h>
#include <stdlib.h>

int main()
{
    static int i=0,test=0,ele,j=0,l=0;
    static int cand[100],ak[1000][100],sum[1000];
    printf("enter the test case,elephant no,candies no and ak ..\n");
    scanf("%d",&test);
    while(i<test)
    {
        scanf("%d %d",&ele,&cand[l]);
        j=0;
        while(j<ele)
        {
            scanf("%d",&ak[l][j]);
            sum[l]+=ak[l][j];
            j++;
        }
        l++;
        i++;
    }
    i=0;
    while(i<test)
    {
     if(sum[i]<=cand[i])
     {
         printf("yes");
     }
     else
     {
         printf("no");
     }
     i++;
     printf("\n");
    }
    return 0;
}
