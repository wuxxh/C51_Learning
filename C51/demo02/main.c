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

void exit1() interrupt 2
{
	if(key1 == 0){
			led1 = ~led1;
			delay_ms(1000);
		}
}

void main(){
	/*while(1){
		if(key1 == 0){
			delay_ms(30);
			if(key1 == 0) //push
			{
				led1 = ~led1;
				delay_ms(100);
			}
		}
	}*/
	PX1=1;
	IT1 = 1; //�����ⲿ�ж�ԴINT0���жϷ�ʽΪ�½��ش���
	EX1 = 1; //�����ⲿ�ж�Դ0
	EA = 1; //cpu�����ж�
	while(1){
		delay_ms(20000);
	}
}