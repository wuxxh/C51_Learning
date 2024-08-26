#include "reg52.h"

sbit BEEP = P2^5;

void delay_ms(unsigned int xms){
	unsigned int i,j;
	for(i=xms;i>0;i--)
	{
		for(j=124;j>0;j--){}
	}
}

void main()
{
	while(1){
		BEEP = 0;
		delay_ms(2);
		BEEP = 1;
		delay_ms(2);
	}
}