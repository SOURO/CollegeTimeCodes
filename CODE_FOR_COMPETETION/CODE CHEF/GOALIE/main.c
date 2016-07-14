#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    int t,*n,i,temp1,temp;
    scanf("%d",&t);
    n=(int*)malloc(sizeof(int)*t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n[i]);
        temp=(int)(log(n[i])/(log(2)));
        temp1=(int)pow(2,temp);
        n[i]=1+((n[i]-temp1)*2);
    }
    for(i=0;i<t;i++)
        printf("\n%d",n[i]);
    return 0;
}
