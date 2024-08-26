#include "reg52.h"

sbit key1 = P3^1;
sbit led1 = P2^0;

void delay_ms(unsigned int xms)   //@12MHz
{
    unsigned int i, j;
    for(i=xms;i>0;i--)
    {
        for(j=124;j>0;j--)
        {}
    }
}


void main(){
	led1 = 0;
	while(1){
		if(key1 == 0){
			delay_ms(10);
			if(key1 == 0) //push
			{
				led1 = ~led1;
				delay_ms(100);
			}
		}
	}
}