#include<stdio.h>
#include<conio.h>
#include<dos.h>
int main()
{
	clrscr();
	sound(440);//FREQUENCY OF SOUND
	delay(500);//DURATION OF SOUND IN MILLI SECONDS
	nosound();
	return(0);
}