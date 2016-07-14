/* A File-copy Program */
#include <stdio.h>
void main( )
{
	FILE *fs, *ft ;
	char ch ;
	clrscr();
	fs = fopen ( "D:\\C\\FILE\\test1.txt", "r" ) ;
	if ( fs == NULL )
	{
		puts ( "Cannot open source file" ) ;
		exit( ) ;
	}
	ft = fopen ( "D:\\C\\FILE\\test2.txt", "w" ) ;
	if ( ft == NULL )
	{
		puts ( "Cannot open target file" ) ;
		fclose ( fs ) ;
		exit( ) ;
	}
	while ( 1 )
	{
		ch = fgetc ( fs ) ;
		if ( ch == EOF )
			break ;
		else
			fputc ( ch, ft ) ;
	}
	fclose ( fs ) ;
	fclose ( ft ) ;
	getch();
}