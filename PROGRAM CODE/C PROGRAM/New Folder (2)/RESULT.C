#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
{
 int a,b;
 int result[10],x,y,c[10];
 int first,second,carry=0,i=0,sum=0,con=0,j,k=0,l=0,m=0;
 clrscr();
 printf("Enter the first number : ");
 scanf("%d",&a);
 printf("Enter the second number : ");
 scanf("%d",&b);
 x=a;
 y=b;
 while(a!=0 && b!=0)
 {
  first=a%10;
  second=b%10;
  sum=first+second+carry;
  m++;
  if(sum>=10)
  {
   con=sum%10;
   carry=sum/10;
   result[i]=con;
   c[m]=carry;
  }
  else
  {
   result[i]=sum;
   carry=0;
   c[m]=carry;
  }
  i++;
  a=a/10;
  b=b/10;

 }
  //if(a!=0)
  //{
	while(a!=0)
	{
	 m++;
	 first=a%10;
	 if(carry!=0)
	 {                                                                                                                                                             ]
	  sum=first+carry;
	  if(sum>=10)                                                                           ..........................
	  {
	   carry=sum/10;
	   sum=sum%10;
	   result[i]=sum;
	   c[m]=carry;
	  }
	  else
	  {
	   result[i]=sum;
	   carry=0;
	   c[m]=carry;
	  }

	 }
	else
	{
	  result[i]=first;
	  carry=0;
	  c[m]=carry;
	}
	i++;
	k++;
	a=a/10;
  }

//}
//else
//{
	while(b!=0)
	{
	 m++;
	 second=b%10;
	 if(carry!=0)
	 {
	  sum=second+carry;
	  if(sum>=10)
	  {
	   carry=sum/10;
	   sum=sum%10;
	   result[i]=sum;
	   c[m]=carry;
	  }
	  else
	  {
	   result[i]=sum;
	   carry=0;
	   c[m]=carry;
	  }

	 }
	 else
	 {
	  result[i]=second;
	  carry=0;
	  c[m]=carry;
	 }
	 i++;
	 b=b/10;
	 l++;
  }

//}
printf("\nThe addition is : \n");
textcolor(21);
cprintf("C:");
for(j=m;j>0;j--)
{
textcolor(27);
cprintf("%d",c[j]);
}
printf("\n");
if(l!=0)
{
printf("   ");
while(l!=0)
{
printf(" ");
l--;
}
printf("%d",x);
printf("\n + %d",y);
}

else if(k!=0)
{

printf("   %d",x);
printf("\n + ");
while(k!=0)
{
printf(" ");
k--;
}
 printf("%d",y);
}
else
{
 printf("   %d",x);
 printf("\n+  ");
 printf("%d",y);
}
printf("\n----------------\n  ");
if(carry!=0)
{
	result[i]=carry;
	for(j=i;j>=0;j--)
	printf("%d",result[j]);
}
else
{
	for(j=i-1;j>=0;j--)
	printf("%d",result[j]);
}
getch();
}
