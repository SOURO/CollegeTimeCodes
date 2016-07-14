#include<dos.h>
#include<conio.h>
void main()
{
	union REGS in,out;
	clrscr();

	in.h.ah=2;// AH -> service number   //2 -> positioning cursor
	in.h.dh=10;// row number
	in.h.dl=2;// column number
	int86(16,&in,&out);// 16 -> positioning,changing size of cursor,writing character,drawing dot on screen etc.
	printf("Hello There!");
	getch();
}