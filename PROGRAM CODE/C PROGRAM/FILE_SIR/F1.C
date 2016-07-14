/* Display contents of a file on screen. */
#include<stdio.h>
void main( ) 
{ 
	FILE *fp; 
	char ch;
	clrscr();
	fp = fopen ( "D:\\C\\FILE\\test1.txt","r");
	while ( 1 )
	{
		ch = fgetc ( fp ) ;
		if ( ch == EOF )
			break ;
		printf ( "%c", ch ) ;
	}
	getch();
	fclose ( fp ) ;
}