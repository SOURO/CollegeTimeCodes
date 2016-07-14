#include<dos.h>
main()
{
	char far *scr;
	int i;
	scr=(char far*)0xB0008000L;
	while(1)
	{
		for(i=0;i<=3999;i=i+2)
		{
			if(*(scr+i)>='A' && *(scr+i)<='Z')
				*(scr+i)=*(scr+i)+32;
			else
			{
				if(*(scr+i)>='a' && *(scr+i)<='z')
				*(scr+i)=*(scr+i)-32;
			}
		}
	}
}