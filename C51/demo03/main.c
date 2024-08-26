/*#include "reg52.h"

sfr IPH = 0xB7;

sbit key = P3^1;
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

void exit_int0() interrupt 0
{
	if(key == 0)
	{
		led1 = ~led1;
		delay_ms(1000);
	}
}

void exit_int1() interrupt 2
{
	if(key == 0)
	{
		led1 = ~led1;
		delay_ms(1000);
	}
}



void main()
{
	IT0 = 1;
	EX0 = 1;
	
	IT1 = 1;
	EX1 = 1;
	
	IPH = 0x04;
	PX0 = 0;
	PX1 = 1;
	
	EA = 1;
	
	
	led1 = 0;
	while(1){
		delay_ms(20000);
	}
}*/

#include <reg52.h>

sfr P4    = 0xe8;                   //for 89C5xRC/RD+ series and 90C5xRc/RD+, location at 0E8H
sbit INT2 = P4^3;
sbit INT3 = P4^2;

sfr XICON = 0xc0;                   //for 89C5xRC/RD+ series and 90C5xRc/RD+, location at 0C0H
sbit PX3  = XICON^7;
sbit EX3  = XICON^6;
sbit IE3  = XICON^5;
sbit IT3  = XICON^4;
sbit PX2  = XICON^3;
sbit EX2  = XICON^2;
sbit IE2  = XICON^1;
sbit IT2  = XICON^0;

sbit key1 = P4^3;
sbit led1 = P2^7;

void delay_ms(unsigned int xms)   //@12MHz
{
    unsigned int i, j;
    for(i=xms;i>0;i--)
    {
        for(j=124;j>0;j--)
        {}
    }
}

void exit2() interrupt 6
{
        //?????????
  if(key1 == 0)
  {
     led1= !led1;
     delay_ms(1000);
  }
}

void main()
{
    IT2 = 1; //????????????
    EX2 = 1; //????2??
    EA = 1;  //????
		led1 = 0;
    while(1)
    {
         delay_ms(20000);
    }                
}
