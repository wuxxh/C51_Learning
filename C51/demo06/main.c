#include "reg52.h"

sbit led = P2^0;

void main(){
	char rdata;
	//ģʽ1:8λbit,�����ʿɱ�(����)
	
	//SCON = 0x40;
	//REN = 1;
	SCON = 0x50; //REN=1,�����������
	
	TMOD &= 0x0F;
	TMOD |= 0x20;
	
	TR1 = 1;
	TL1 = 0xFD;
	TH1 = 0xFD;
	
	
	while(1){
		if(RI == 1){
			RI = 0;
			rdata = SBUF;
			if(rdata == 'O'){
				//����led
				led = 0;
			}
			if(rdata == 'C'){
				led = 1;
			}
		}
	}
}