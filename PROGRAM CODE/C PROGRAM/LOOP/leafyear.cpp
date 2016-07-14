 #include<stdio.h>
 #include<conio.h>
 void main()
 {
	int x;
	clrscr();
	printf("enter a year");
	scanf("%d",&x);
	if(x%100!=0&&x%4==0||x%400==0)
	{
		printf("the year is leap year");
	}
	else
	{
		printf("the year is not leap year");
	}
	getch();
}