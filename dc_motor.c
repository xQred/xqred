#include<reg51.h>
sbit motorA=P2^0;
sbit motorB=P2^1;
sbit sw1=P1^0;
sbit sw2=P1^1;

void main(void)
{
	//sw1=sw2=1;
	//in1=in2=0;
	while(1)
	{
		if(sw1==0)
		{ 
			motorA=1;
			motorB=0;
		}
		else if (sw2==0)
		{
			motorA=0;
			motorB=1;
		}
		else
		{
			motorA=0;
			motorB=0;
		}
	}
}


			
		
		
	
