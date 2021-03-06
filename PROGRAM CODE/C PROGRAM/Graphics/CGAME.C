/* VIDEO GAME from GRAPHICS UNDER C */

/*  ********************** PAGE-166 *********************************      */

#include "process.h"
#include "dos.h"
#include "stdlib.h"
#include "graphics.h"
#include "stdio.h"

#define NULL 0
#define YES 1
#define NO 0

int maxx,maxy,midx,midy;
int bri[3][16];
char str[20];

/* draws a brick at the proper position */
drawbrick(int lx, int ly)
{
	setfillstyle(SOLID_FILL,RED);
	setcolor(WHITE);
	rectangle(lx,ly,lx+40,ly+25);
	rectangle(lx+2,ly+2,lx+40-2,ly+25-2);
	floodfill(lx+3,ly+3,WHITE);
	return 0;
}

/* draws bricks at the start of the game */
bricks()
{
	int i,j,lx=1,ly=0;
	for(i=0;i<3;i++) /* 3 rows */
	{
		for (j=0;j<=16;j++) /* 16 columns */
		{
			/* draw a brick at appropriate coordinates */
			drawbrick(lx,ly);

			lx=lx+40;
		}
		lx=0;
		ly=ly+25;
	}
	return 0;
}


/* erases the specified brick */
erasebrick(int b, int l)
{
	/* b-brick number, l-layer */
	setfillstyle(SOLID_FILL,BLACK);
	setcolor(BLACK);
	rectangle(b*40,l*25,(b*40)+40,(l*25)+25);
	rectangle(b*40+1,l*25,(b*40)+40-1,(l*25)+25-1);
	rectangle(b*40+2,l*25,(b*40)+40-2,(l*25)+25-2);
	floodfill(b*40+3,l*25+3,BLACK);
	setcolor(WHITE);
	return 0;
}

/* plays different types of music */
music(int type)
{
	/* natural frequencies of 7 notes */

	float octave[7]={130.81,146.83,164.81,174.61,196,220,246.94};
	int n,i;

	switch(type)
	{
		case 1:
			for(i=0;i<7;i++)
			{
				sound(octave[i]*8);
				delay(30);
			}
			nosound();
			break;

		case 2:
			for(i=0;i<15;i++)
			{
				n=random(7);
				sound(octave[n]*4);
				delay(100);
			}
			nosound();
			break;

		case 3:
			while(!kbhit())
			{
				n=random(7);
				sound(octave[n]*4);
				delay(100);
			}
			nosound();

			/* flush the keyboard buffer */

			if(getch()==0)
				 getch();
			break;

		case 4:
			for(i=4;i>=0;i--)
			{
				sound(octave[i]*4);
				delay(15);
			}
			nosound();
			break;

		case 5:
			sound(octave[5]*2);
			delay(50);
			nosound();
	}
	return 0;
}

/* creates opening screen */
mainscreen()
{
	/* array showing the position where a brick is needed to form the figure BRICKS*/
	int ff[12][40]=
{
1,1,1,1,0,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,1,1,1,0,0,1,0,0,0,0,1,0,0,0,1,1,1,0,
1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,
1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,
1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,
1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,
1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,
1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,
1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,
1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,0,0,0,0,1,
1,1,1,1,0,0,0,1,0,0,0,0,1,0,1,1,1,1,1,0,0,0,1,1,1,0,0,1,0,0,0,0,1,0,0,1,1,1,1,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};
	int i,j,lx=0,ly=0,ch;

	/* draw boundary */
	rectangle (0,0,maxx,maxy);

	/* form the word BRICKS */
	for(i=0;i<12;i++)
	{
		for(j=0;j<40;j++)
		{
			if(ff[i][j])
			{
				setfillstyle (SOLID_FILL,RED);
				rectangle (lx,ly,lx+15,ly+9);
				floodfill (lx+3,ly+3,WHITE);
			}
			lx=lx+16;
		}
		lx=0;
		ly=ly+10;
	}

	/* draw pattern at the bottom of the screen */
	line(0,maxy-12,maxx,maxy-12);
	setfillstyle(XHATCH_FILL,WHITE);

	/* draw the paddle and the ball */
	setfillstyle(SOLID_FILL,WHITE);
	rectangle(midx-25,maxy-7-12-50,midx+25,maxy-12-50);
	circle (midx,maxy-13-12-50,12);
	music(3);

	/* display menu */
	while(1)
	{
		/* clear the region below the word BRICKS */
		setviewport(1,125-12,maxx-1,maxy-1,1);
		clearviewport();

		setviewport (0,0,maxx,maxy,1);
		setcolor (WHITE);
		settextstyle (DEFAULT_FONT,0,2);

		outtextxy(20,235,"Selectany of the following:");
		outtextxy(20,265,"Play (P)");
		outtextxy(20,295,"Instructions (I)");
		outtextxy(20,325,"Exit (E)");

		ch=0;

		/* continue till the correct choice is made */
		while (!(ch=='E' || ch=='I' || ch=='P'))
		{
			fflush(stdin);

			/* if a special key is hit, flush the keyboard buffer */
			if((ch=getch())==0)
				getch();
			else
				ch=toupper(ch);
		}

		 if (ch=='P')
			break;

		 switch(ch)
		 {
			 case 'I':
				 setviewport(1,125-12,maxx-1,maxy-1,1);
				 clearviewport();

				 setviewport (0,0,maxx,maxy,1);
				 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
				 outtextxy(20,200,"Instructions:-");
				 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
				 outtextxy(20,240,"Use left and right arrow keys to move paddle.");
				 outtextxy(20,270,"If you don't collect the ball on the paddle, you lose the ball.");
				 outtextxy(20,300,"On taking a brick you gain 5 points.");
				 outtextxy(20,330,"On taking a brick you gain 5 points.");
				 outtextxy(20,365,"Press any key...");
				 fflush(stdin);
				 if(getch()==0)
					 getch();
				 break;

			 case 'E':
				 closegraph();
				 restorecrtmode();
				 exit(0);
		 }
	 }

	 setviewport(1,125-12,maxx-1,maxy-1,1);
	 clearviewport();

	 /* prompt the user for the level desired */
	 setviewport(0,0,maxx,maxy,1);
	 settextstyle(DEFAULT_FONT,0,2);
	 outtextxy(20,150,"Select any of the following levels");
	 outtextxy(20,200,"Noviec (N)");
	 outtextxy(20,245,"Advanced (A)");
	 outtextxy(20,290,"Expert (E)");

	 /* get user's choice */
	 fflush(stdin);
	 if((ch=getch())==0)
		 getch();

	 clearviewport();

	 /* return the choice made by the user */
	 return(ch);
}


void main()
{
	union REGS ii,oo;
	int ballx, bally, paddlex, paddley,dx=1,dy=-1,oldx, oldy;
	int gm=VGAHI, gd=VGA, playerlevel,start=0;
	int i, flag=0, speed=15, welldone=NO, score=0, chance=4, area;
	int layer[3]={25,50,75}, limit=75, currentlayer=2;
	char *p1,*p2;


	/* initialise the graphics system */
	initgraph (&gd,&gm,"C:\\tc\\bgi");

	/* get the maximum x and y screen coordinates */
	maxx=getmaxx();
	maxy=getmaxy();

	/* calculate center of screen */
	midx=maxx/2;
	midy=maxy/2;

	/* display opening screen and receive player's level */
	playerlevel=mainscreen();

	/* set speed of ball as per the level chosen */
	switch (playerlevel)
	{
		case 'A':
		case 'a':
			speed=10;
			break;

		case 'E':
		case 'e':
		  speed=5;
	}

	/*  draw the bricks, the paddle and the ball */
	rectangle (0,0,maxx,maxy-13-13);
	bricks();

	setfillstyle (SOLID_FILL, YELLOW);
	rectangle (midx-50,maxy-50,midx+50,maxy-20-9);
	floodfill (midx,maxy-33,WHITE);

	setfillstyle (SOLID_FILL, LIGHTBLUE);
	circle (midx,maxy-50-13,12);
	floodfill (midx,maxy-50-15,WHITE);

	/* allocate memory for storing the image of the ball */
	area=imagesize (midx-12,maxy-50-13-12,midx+12,maxy-50-1);
	p1=malloc (area);

	/* allocate memory for storing the image of the paddle */
	area=imagesize (midx-50,maxy-50,midx+50,maxy-20-9);
	p2=malloc (area);

	/* if memory allocation unsuccessful */
	if (p1==NULL||p2==NULL)
	{
		puts ("Insufficient memory!!");
		exit(1);
	}

	/*  store the image of the paddle and the ball into allocated memory */
	getimage (midx-12,maxy-50-13-12,midx+12,maxy-50-1,p1);
	getimage (midx-50,maxy-50,midx+50,maxy-20-9,p2);

	/*  store current position of the paddle and ball */
	paddlex=midx-50;
	paddley=maxy-50;
	ballx=midx-12;
	bally=maxy-50-13-12;

	/*  display balls in hand (initially 3) */
	settextstyle (0,0,1);
	outtextxy (300,470,"Balls remaining:");

	for (i=0;i<3;i++)
	{
		circle (515+i*40,maxy-12,12);
		floodfill (515+i*40,maxy-12,WHITE);
	}

	/*  display initial score */
	outtextxy (50,470,"Your Score:");
	sprintf(str,"%4d",score);
	outtextxy (140,470,str);

	/*  select font and alignment for displaying text */

	settextjustify (CENTER_TEXT,CENTER_TEXT);
	settextstyle (0,HORIZ_DIR,0);
	while (1)
	{
		if(!start)
		{
			delay(2000);
			start=1;
		}
		else
		{

		start=1;
		flag=0;

		/*  save the current x and y coordinates of the ball */
		oldx=ballx;
		oldy=bally;

		/*  update ballx and bally to move the ball in appropriate direction */
		ballx=ballx+dx;
		bally=bally+dy;

		/*  as per the position of ball determine the layer of bricks to check */
		if (bally>50)
		{
			limit=75;
			currentlayer=2;
		}
		else
		{
			if (bally>25)
			{
				limit=50;
				currentlayer=1;
			}
			else
			{
				limit=25;
				currentlayer=0;
			}
		}

		/*  if the ball hits the left boundary, deflect it to the right */
		if (ballx<=1)
		{
			music(5);
			ballx=1;
			dx=-dx;
		 }

		 /* if the ball hits the right boundary, deflect it to the right */
		 if (ballx>=maxx-24-1)
		 {
			music(5);
			ballx=maxx-24-1;
			dx=-dx;
		 }

		 /*  if the ball hits the top boundary, deflect it down */
		if (bally<=1)
		{
			music(5);
			bally=1;
			dy=-dy;
		}

		/*  if the ball is in the area occupied by the bricks */
		if (bally<limit)
		{
			/*  if there is no brick present exactly at the top of the ball */
			if (bri[currentlayer][(ballx+10)/40]==1)
			{
				/*  determine if he boundary of the ball touches a brick */
				for (i=1;i<=6;i++)
				{
					/* check whether ther is a brick to the right of the ball */
					if (bri[currentlayer][(ballx+i+10)/40]==0)
					{
						/*  if there is a brick */
						ballx=ballx+i;
						flag=1;
						break;
					}

					/* check whether there is a brick to the left of the ball */
					if (bri[currentlayer][(ballx-i+10)/40]==0)
					{
						ballx=ballx-i;
						flag=1;
						break;
					}
				}

				/*  if the ball does not touch a brick at the top,left or right */
				if (!flag)
				{
					/* check if the ball has moved above the current layer */
					if (bally<layer[currentlayer-1])
					{
						/* if so change current layer appropriately */
						currentlayer--;
						limit=layer[currentlayer];
					}

					/*  put the image of the ball at the old coordinates */
					putimage (oldx,oldy, p1,OR_PUT);

					/* erase the image at the old coordinates */
					putimage (oldx,oldy, p1,XOR_PUT);

					/*  place the image of the ball at the new coordinates */
					putimage (ballx,bally, p1,XOR_PUT);

					/* introduce delay */
					delay (speed);

					/* carry on with moving the ball */
					continue;
				}
			}

			/*  control comes to this point only if the ball is touching a brick */
			music(4);
			/* erase the brick hit by the ball */
			erasebrick((ballx+10)/40,currentlayer);

			/*  if the brick hit happens to be on the extreme right */
			if ((ballx+10)/40>=15); /* redraw right boundary */

			/* if the brick hit happens to be on the extreme left */
			if ((ballx+10)/40==0)
				line (0,0,0,75); /* redraw left boundary */

			/* if the brick hit happens to be in the topmost layer */
			if(currentlayer==0)
				line(0,0,maxx,0); /* redraw top boundary */

			/* set appropriate array element to 1 to indicate absence of brick */
			bri[currentlayer][(ballx+10)/40]=1;

			bally=bally+1; /* update the y coordinate */
			dy=-dy; /* change the direction of the ball */
			score+=5; /* increement score */

			setviewport (150,470,180,479,1);
			clearviewport();
			setviewport (0,0,maxx,maxy,1);

			sprintf(str, "%4d",score);
			outtextxy (152,475,str);

			/* if the first brick is hit during a throw */
			if(welldone==NO)
				welldone=YES;
			else
			{
				/* for the consecutive bricks hit during the same throw */
				settextstyle(7,0,4);
				outtextxy (midx,midy, "Well done!");
				music(1);
				settextstyle(0,0,1);
			}
		}
		/* clear part of the screen used for displaying Well done message */
		if (bally>75 && welldone==YES)
		{
			setviewport (midx-40*2.5,midy-40/2,midx+40*2.5,midy+40/2,1);
			clearviewport();
			setviewport (0,0,maxx,maxy,1);
			welldone=NO;
		}

		/* if the ball has reached the bottom */
		 if(bally>=maxy-50-24-1)
		 {
			 welldone=NO;

			 /* if the paddle has missed the ball */
			 if(ballx<=paddlex-24 || ballx>paddlex+100)
			 {
				/* continue the descent of the ball */
				while (bally<maxy)
				{
					/* erase the image of the ball at the old coordinates */
					putimage (oldx,oldy,p1,XOR_PUT);

					/* put the image of the ball at the updated coordinates */
					putimage (ballx,bally,p1,XOR_PUT);

					/* introduce delay */
					delay(speed);

					/* save the current x and y coordinates of the ball */
					oldx=ballx;
					oldy=bally;

					/* update ballx and bally to move the ball in appropriate direction */
					ballx=ballx+dx;
					bally=bally+dy;

				}

				chance--; /* decrement the number of chances */
				score-=10; /* decrement 20 points for each ball lost */

				setviewport (150,470,180,479,1);
				clearviewport();
				setviewport(0,0,maxx,maxy,1);

				sprintf(str, "%4d",score);
				outtextxy(152,475,str);
				music(2);

				/* erase one out of te available balls */
				if(chance)
				{
					setcolor(BLACK);
					putimage(515+(chance-1)*40-12,maxy-19-5,p1,XOR_PUT);
					start=0;

					/*  store current position of the paddle and ball */
					paddlex=midx-50;
					paddley=maxy-50;
					ballx=midx-12;
					bally=maxy-50-13-12;
				}

				/* if all the balls are lost */
				if(!chance)
				{
					settextstyle (7,0,4);
					outtextxy(midx,midy, "I warned you! Try again");
					music(3);
					getch();
					closegraph();
					restorecrtmode();
					exit(0);
				}
			}
			/* if ball is collected on paddle */
			else
			{
				music(5);
				bally=maxy-13-12-50-1; /* restore the y coordinate of ball */
				if(dy==1)
					dy=-dy; /* deflect the ball upwards */
			}
		}

		/* put the image of the ball at the old coordinates */
		putimage (oldx,oldy,p1,OR_PUT);

		/* erase the image of the ball at the old coordinates */
		putimage(oldx,oldy,p1,XOR_PUT);

		/* put the image of the ball at the updated coordinates */
		putimage(ballx,bally,p1,XOR_PUT);

		/* if all the bricks have been destroyed */
		if(score==(48*5)-((4-chance)*20))
		{
			settextstyle(7,0,4);
			outtextxy(midx,midy, "You win!!!");

			if(score<240)
			{
				outtextxy(midx,midy+30,"Try to score 240");
				getch();
			}
			else
			{
				outtextxy(midx,midy+30,"You are simply GREAT!");			 				music(3);
				getch();
			 }
			 closegraph();
			 restorecrtmode();
			 exit(0);
		 }

		 /* introduce delay */
		 delay(speed);

		 /* if the user has pressed a key to move the paddle */
		 if(kbhit())
		 {
			 /* issue interrupt to obtain the ASCII and scan codes of key hit */
			 ii.h.ah=0;
			 int86(22,&ii,&oo);

			 /* input the image of the paddle at the old coordinates */
			 //putimage(paddlex,paddley,p2,XOR_PUT);

			 /* erase the image of the paddle at the old coordinates */
			 putimage(paddlex,paddley,p2,XOR_PUT);

			 /* if Esc key has been pressed */
			 if(oo.h.ah==1)
				exit(0);

			 /* right arrow key */
			 if(oo.h.ah==75)
				paddlex=paddlex-20;

			 /* left arrrow key */
			 if(oo.h.ah==77)
				paddlex=paddlex+20;

			 /* if paddle goes beyond left boundary */
			 if(paddlex<1)
				 paddlex=1;

			 /* if paddle goes beyond right boundary */
			 if(paddlex>588)
				 paddlex=588;

			 /* put the image of the paddle at the proper position */
			 putimage(paddlex,paddley,p2,XOR_PUT);
		 }
	 }
	 }
}
