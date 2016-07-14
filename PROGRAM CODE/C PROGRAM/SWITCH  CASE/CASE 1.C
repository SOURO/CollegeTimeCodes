#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
       int ch,n,r,p,C,nu,den,a,b,c,i,u,d,t,fact=1,s=0;
       while(1)
       {
	    clrscr();
	    printf("press 1 for permutation\n");
	    printf("press 2 for combination\n");
	    printf("press 3 for factorial\n");
	    printf("press 4 for fibbonacci\n");
	    printf("press 5 for armstrong number for a range\n");
	    printf("press 6 for exit\n");
	    printf("\nEnter your choice:");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	       case 1:
		    printf("\n enter the value of n & r of p");
		    scanf("%d%d",&n,&r);
		    nu=1;
		    for(i=1;i<=n;i++)
		    {
		      nu*=i;
		    }
		    den=1;
		    for(i=1;i<=n-r;i++)
		    {
		      den*=i;
		    }
		    p=nu/den;
		    printf("%dp%d=%d\n",n,r,p);
		    break;
		case 2:
			 printf("\n enter the value of n & r of C");
			 scanf("%d%d",&n,&r);
			 printf("\n armstrong no. from %d to %d",n,r);
			 nu=1;
			 for(i=1;i<=n;i++)
			 {
				nu*=i;
			 }
			 den=1;
			 for(i=1;i<=r;i++)
			 {
				den*=i;
			 }
			 for(i=1;i<=n-r;i++)
			 {
				den*=i;
			 }
			 C=nu/den;
			 printf("%dC%d=%d\n",n,r,C);
			 break;
		case 3:
			 printf("\nenter the value of n");
			 scanf("%d",&n);
			 fact=1;
			 for(i=1;i<=n;i++)
			 {
				fact*=i;
			 }
			 printf("\n (%d)!=%d",n,fact);
			 break;
		 case 4:
			 printf("\n enter the number of terms of fibonacci series");
			 scanf("%d",&n);
			 a=0;
			 b=1;
			 printf("\n %d terms of the series:%d%d",n,a,b);
			 for(i=3;i<=n;i++)
			 {
				 c=a+b;
				 printf("%d",c);
				 a=b;
				 b=c;
			  }
			  break;
		  case 5:
			  printf("\n enter the starting & ending no.");
			  scanf("%d%d",&t,&u);
			for(i=t;i<=u;i++)
         {
			n=i;
			s=0;
			while(n!=0)
			{
				 d=n%10;
				 s=(d*d*d)+s;
				 n=n/10;
			 }
			 if(i==s)
			 {
				  printf("\n %d",i);
			 }
				}
				break;
			 case 6:
			printf("\n THANK YOU");
			getch();
			exit(0);
		 }
		 getch();
		 }
 }