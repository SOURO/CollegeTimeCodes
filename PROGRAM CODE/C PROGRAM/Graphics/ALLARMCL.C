#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>

void main()
{
	int hh,mm,ss,ahh,amm,ass;
	int key,count;
	char str[40];
	union REGS in,out;

	clrscr();
	nosound();
	printf("Enter Alarm Time(hh mm ss) 24 HRs :");
	scanf("%d %d %d",&ahh,&amm,&ass);
	while(1)
	{
		if(kbhit())
		{
			key=getch();
			if(key==27)
				exit();
		}

		in.h.ah=0x02;
		int86(0x1A,&in,&out);

		sprintf(str,"%x:%x:%x",out.h.ch,out.h.cl,out.h.dh);
		sscanf(str,"%d:%d:%d",&hh,&mm,&ss);
		printf("PRESS Esc TO DISABLE ALLARM\n\n");
		printf("ALLARM TIME(24 HRs)  : %d:%d:%d\n",ahh,amm,ass);
		printf("\nCURRENT TIME(24 HRs) : ");
		puts(str);

		if(hh==ahh && mm==amm && ss==ass)
		{
			clrscr();
			count=1;
			while(count<=120)
			{
				if(kbhit())
				{
					key=getch();
					if(key==27)
					{
						nosound();
						exit();
					}
				}
				printf("ALLARM WILL CONTINUE FOR 2 MINUTES(PRESS Esc TO STOP)");
				printf("\n%d SECONDS REMAINING",120-count);
				sound(64*8);
				delay(1000);
				count++;
				clrscr();
			}
			amm+=3;
			if(amm>60)
			{
				ahh++;
				amm%=60;
			}
		}
		nosound();
		delay(500);
		clrscr();
	}
}