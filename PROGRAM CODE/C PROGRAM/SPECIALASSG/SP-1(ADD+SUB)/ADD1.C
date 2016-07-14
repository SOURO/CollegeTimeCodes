#include<stdio.h>
#include<conio.h>

long unsigned add(long unsigned,long unsigned);
void present(long unsigned,long unsigned,long unsigned);

int c[50],j=0;

void main()
{

	long unsigned n1,n2,num1,num2,sum1;


	clrscr();

	printf("ENTER A NUMBER:\n");
	scanf("%lu",&num1);

	printf("\nENTER ANOTHER NUMBER:\n");
	scanf("%lu",&num2);

	n1=num1;
	n2=num2;

	sum1=add(num1,num2);
	present(sum1,n1,n2);

	printf("\n\nCONGRATS..YOUR OPERATION IS SUCESSFUL..");


	getch();

}

long unsigned add(long unsigned num1,long unsigned num2)

{
	long unsigned n11,n22,sum1=0;
	int carry=0,sum,arr[50],i=0,l;

	while(num1!=0&&num2!=0)
	{
	   n11=num1%10;
	   n22=num2%10;

	   sum=n11+n22+carry;

	   if(sum>=10)
	   {
			carry=1;
			c[j++]=carry;
			arr[i++]=sum%10;
	   }

	   else
	   {
			arr[i++]=sum;
			carry=0;
			c[j++]=carry;
	   }

	   num1=num1/10;
	   num2=num2/10;
	}

	while(num1!=0)
	{
		n11=num1%10;
		sum=n11+carry;


		if(sum>=10)
		{
			arr[i++]=sum%10;
			carry=sum/10;
			c[j++]=carry;
		}
		else
		{
			arr[i++]=sum;
			carry=0;
			c[j++]=carry;
		}
		num1=num1/10;
	}

	while(num2!=0)
	{
		n22=num2%10;
		sum=n22+carry;

		if(sum>=10)
		{
			arr[i++]=sum%10;
			carry=sum/10;
			c[j++]=carry;
		}
		else
		{
			arr[i++]=sum;
			carry=0;
			c[j++]=carry;
		}
		num2=num2/10;
	}

	if(carry!=0)
	{
		arr[i++]=carry;
		for(l=i-1;l>=0;l--)
			sum1=(sum1*10)+arr[l];
		return sum1;

	}

	else
	{
		for(l=i-1;l>=0;l--)
				sum1=(sum1*10)+arr[l];
		return sum1;

	}
}

void present(long unsigned sum1,long unsigned n1,long unsigned n2)
{
	int k;

	printf("\n\nTHE ADDITION IS:\n\n");
	printf("\nCARRYS ARE : ");


	for(k=j-1;k>=0;k--)
	{
		printf("%d",c[k]);
	}
	printf("\n\n\t\t %10lu",n1);
	printf("\n\t\t+");
	printf("\n\t\t %10lu",n2);
	printf("\n\t\t__________________\n\n");
	printf("\t\t ");
	printf("%10lu",sum1);
}