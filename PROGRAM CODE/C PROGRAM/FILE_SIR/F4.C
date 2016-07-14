/* Receives strings from keyboard and writes them to file */
#include <stdio.h>
void main( )
{
	FILE *fp ;
	char s[80] ;
	clrscr();
	fp = fopen ( "D:\\C\\FILE\\MSG.TXT", "w" ) ;
	if ( fp == NULL )
	{
		puts ( "Cannot open file" ) ;
		exit( ) ;
	}

	printf ( "\nEnter a few lines of text:\n" ) ;
	while ( strlen ( gets ( s ) ) > 0 )
	{
		fputs ( s, fp ) ;
		fputs ( "\n", fp ) ;
	}
	fclose ( fp ) ;
	getch();
}