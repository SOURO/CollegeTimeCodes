 #include<conio.h>
int leap year (int y);
void main()
{
	int y,x;
	clrscr();
	printf("enter a year");
	scanf("%d",&y);
	x=leap year(Y);

		if(x%100!=0&&x%4==0||x%400==0)
		{
			return(1);
		}
		else
		{
			return(0);
		}
		if(x==1)
		{
		printf("leap year");
		}

	getch();
}