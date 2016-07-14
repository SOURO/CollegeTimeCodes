#include<stdio.h>
#include<conio.h>
void main()
{
	int m[10],total=0,i,n;
	float per;
	clrscr();
	printf("\nhow many subject");
	scanf("%d",&n);
	printf("\nenter %d subject mark",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m[i]);
		total=total+m[i];
	}
		printf("\nthe total marks is %d",total);
		per=(float)total/n;
		printf("\nthe persentage of total marks is%f",per);
		if(per>=90)
		printf("\ngrade O");
		else if(per>=80)
		printf("grade E");
		else if(per>=70)
		printf("\ngrade A");
		else if(per>=60)
		printf("\ngrade b");
		else if(per>=50)
		printf("\ngrade c");
		else if(per>=40)
		printf("\ngrade d");
		else if(per<40)
		printf("\nfail");
		getch();
}