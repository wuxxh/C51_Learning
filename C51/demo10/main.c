#include "reg52.h"
unsigned char speed,compare;
#define TIMS (65536 - 922)

sbit dc_an1 = P1^0;

void delay_ms(unsigned int xms)   //@12MHz
{
    unsigned int i, j;
    for(i=xms;i>0;i--)
    {
        for(j=124;j>0;j--)
        {}
    }
}

void Timer0() interrupt 1
{
        //每次产生中断后重新设置下次定时器初值 - 1毫秒产生1次中断
        TH0 = TIMS >> 8;
        TL0 = TIMS;
        //当compare为10时，输出10ms高电平，90ms低电平
        //当compare为60时，输出60ms高电平，40ms低电平
        //当compare为90时，输出90ms高电平，10ms低电平
        speed++;//定时计数器的计数值，1ms加1
        speed%=100;//限制speed在0-100内
        if(speed<compare)//计数值与比较值进行比较
        {
            dc_an1=1;
        }
        else
        {       
            dc_an1=0;
        }
}

void main(){
	while(1){
				TMOD = 0x01;      //配置定时器0为16位定时器，TH0、TL0全用
        TH0 = TIMS >> 8;  //设置定时初值高8位
        TL0 = TIMS;       //设置定时初值低8位
        ET0 = 1;  //开启定时器0中断                                          
        EA  = 1;  //开启全局中断                                                      
        TR0 = 1;  //定时器0开始计数  
        //初始化电机，停止运行
        dc_an1 = 0;
		
		
		while(1){
            compare=1;
            delay_ms(5000);
            compare=5;
            delay_ms(5000);
            compare=10;
            delay_ms(5000);
            compare=15;
            delay_ms(5000);
        }
	}
}