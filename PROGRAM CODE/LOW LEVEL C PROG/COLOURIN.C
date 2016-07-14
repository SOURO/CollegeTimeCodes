#include<dos.h>
main()
{
	char far *scr;
	int i;
	scr=(char far*)0xB0008000L;
	while(1)
	{
		for(i=1;i<=3999;i=i+2)
		{
			if(*(scr+i)>=0 && *(scr+i)<=255)
				*(scr+i)=*(scr+i)+i;

		}
	}
}