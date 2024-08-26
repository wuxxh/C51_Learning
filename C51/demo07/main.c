#include "reg52.h"

sbit led = P2^0;
char rdata;

void delay_ms(unsigned int xms)   //@12MHz
{
    unsigned int i, j;
    for(i=xms;i>0;i--)
    {
        for(j=124;j>0;j--)
        {}
    }
}

void uart_receive() interrupt 4
{
	if(RI == 1){
			RI = 0;
			rdata = SBUF;
			if(rdata == 'O'){
				//点亮led
				led = 0;
			}
			if(rdata == 'C'){
				led = 1;
			}
		}
}


void main(){
	//模式1:8位bit,波特率可变(常用)
	//SCON = 0x40;
	//REN = 1;
	SCON = 0x50; //REN=1,允许接受数据
	
	TMOD &= 0x0F;
	TMOD |= 0x20;
	
	TR1 = 1;
	TL1 = 0xFD;
	TH1 = 0xFD;
	
	ES = 1;
	EA = 1;
	
	while(1){
		delay_ms(20000);
	}
}