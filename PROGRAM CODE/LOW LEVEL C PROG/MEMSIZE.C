#include<dos.h>
main()
{
	unsigned int far *mem;
	mem=(char far*)0x413;
	printf("\n Base memory size =%uKB ",*mem);
}
