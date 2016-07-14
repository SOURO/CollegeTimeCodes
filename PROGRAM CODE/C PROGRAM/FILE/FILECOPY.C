#include<stdio.h>
#include<conio.h>
#define null 0

void main()

{

	FILE *fs,*ft;
	char ch;

	fs=fopen("soura.txt","r");

	if(fs==null)
	{
		puts("cannot open source file");
		exit(0);
	}

	ft=fopen("soura1.txt","w");

	if(ft==null)
	{
		puts("caannot open target file");
		fclose(fs);
		exit(1);
	}

	while(1)
	{
		ch=fgetc(fs);
		if(ch==EOF)
			break;
		else
			fputc(ch,ft);
	}


	fclose(fs);
	fclose(ft);

}
