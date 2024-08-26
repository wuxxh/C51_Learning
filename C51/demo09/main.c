#include "reg52.h"

sbit led = P2^0;

void Delayus(unsigned int t)	//@11.0592MHz
{
	while(t--){
		unsigned int i;
		i=2;
		while(--i);
	}
}


void main(){
	int time = 0;
	led = 0;
	
	while(1){
		for(time = 0;time < 300;time++){ //´Ó°µÖð½¥±äÁÁ
			led = 0;
			Delayus(time);
			led = 1;
			Delayus(300 - time);
		}
		for(time = 0;time < 300;time++){ //´ÓÁÁÖð½¥±ä°µ
			led = 1;
			Delayus(time);
			led = 0;
			Delayus(300 - time);
		}
	}
}