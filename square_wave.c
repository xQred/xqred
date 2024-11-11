#include<reg51.h>
void delay(unsigned int time)
{
	int i,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<5000;j++);
	}
}
void main()
{
	while(1)
	{
		P0=0xFF;
		delay(100);
		P0=0x00;
		delay(100);
	}
}
