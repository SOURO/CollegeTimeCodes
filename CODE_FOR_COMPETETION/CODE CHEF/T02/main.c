#include <stdio.h>
#include <string.h>
#include<math.h>
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
int main() {

     int n[1000],k,t,i,j;
     char buffer[9],buffer2[1000][9];
     scanf("%d",&t);
     for(i=0;i<t;i++)
     {
         scanf("%d %d",&n[i],&k);
         switch((n[i]-1)/2)
         {
             case 0:
                    sprintf(buffer,"%d",1+(k-1));
                    break;
             case 1:
                    sprintf(buffer,"%d",10+(k-1));
                    break;
             case 2:
                    sprintf(buffer,"%d",100+(k-1));
                    break;
             case 3:
                    sprintf(buffer,"%d",1000+(k-1));
                    break;
             case 4:
                    sprintf(buffer,"%d",10000+(k-1));
                    break;
         }
         j=0;
         while(buffer[j]!='\0')
         {
            buffer2[i][j]=buffer[j];
            j++;
         }
         buffer2[i][j]='\0';
     }
     for(i=0;i<t;i++)
     {
         printf("\n%s",buffer2[i]);
         strrev(buffer2[i]);
         j=0;
         if(n[i]%2!=0)
            printf("%s",buffer2[i]+1);
         else
            printf("%s",buffer2[i]);
     }
     return 0;

}

