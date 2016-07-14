/* Read records from a file using structure */
#include <stdio.h>
void main( )
{
	FILE *fp ;
	struct emp
	{
		char name[40] ;
		int age ;
		float bs;
	} ;
	struct emp e ;
	clrscr();
	fp = fopen ( "D:\\C\\FILE\\EMPLOYEE.TXT", "r" ) ;
	if ( fp == NULL )
	{
		puts ( "Cannot open file" ) ;
		exit( ) ;
	}

	while ( fscanf ( fp, "%s %d %f", e.name, &e.age, &e.bs ) != EOF )
		printf ( "\n%s %d %f", e.name, e.age, e.bs ) ;

	fclose ( fp ) ;
	getch();
}