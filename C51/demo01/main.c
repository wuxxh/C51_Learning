#include "reg52.h"
#include "intrins.h"

sbit LED1 = P2^0;
sbit LED2 = P2^1;
sbit LED3 = P2^2;


void Delay500ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main(){
	//LED1 = 0;
	while(1){
		LED3=1;
		LED1=0;
		Delay500ms();
		LED1=1;
		LED2=0;
		Delay500ms();
		LED2=1;
		LED3=0;
		Delay500ms();
		
	}
}