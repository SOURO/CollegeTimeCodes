/* Reads strings from the file and displays them on screen */
#include <stdio.h>
void main( )
{
	FILE *fp ;
	char s[80] ;
	clrscr();
	fp = fopen ( "D:\\C\\FILE\\MSG.TXT", "r" ) ;
	if ( fp == NULL )
	{
		puts ( "Cannot open file" ) ;
		exit( ) ;
	}

	while ( fgets ( s, 79, fp ) != NULL )
		printf ( "%s" , s ) ;

	fclose ( fp ) ;
	getch();
}