#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int N[1000000],t,i,result;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&N[i]);
    }
    for(i=0;i<t;i++)
    {
        result=(int)sqrt(N[i]);
        printf("%d\n",result);
    }
    return 0;
}
