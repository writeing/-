#include <STC12C5A60S2.H>
char code table[8]={0x01,0x03,0x07,0x08,0x10,0x30,0xf0,0xa5};

void delay()
{
	int x=50,y=125;
	while(x--)
	{
		while(y--);
	}
}
int main()
{
	int i=0;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			P0 = table[i];
			delay();
		}
					
	}
}