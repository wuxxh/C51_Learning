#include "reg52.h"
#include <stdio.h>  

sfr WDT_CONTR = 0xe1;

void UartInit(void)                //9600bps@11.0592MHz
{
        PCON &= 0x7F;                //波特率不倍速
        SCON = 0x50;                //8位数据,可变波特率
        TMOD &= 0x0F;                //清除定时器1模式位
        TMOD |= 0x20;                //设定定时器1为8位自动重装方式
        TL1 = 0xFD;                //设定定时初值
        TH1 = 0xFD;                //设定定时器重装值
        ET1 = 0;                //禁止定时器1中断
        TR1 = 1;                //启动定时器1
}

/*
**重写printf调用的putchar函数，重定向到串口输出
**需要引入头文件<stdio.h>
*****/
char putchar(char dat){
        //输出重定向到串口
        SBUF = dat;     //写入发送缓冲寄存器
        while(!TI);    //等待发送完成，TI发送溢出标志位 置1
        TI = 0;      //对溢出标志位清零
        return dat;  //返回给函数的调用者printf
}
void delayms(unsigned int xms) {
    unsigned int i,j;
    for (i=xms;i>0;i--)
    for(j=110;j>0;j--);
}

void main(){
	UartInit();
	printf("system init\n");
	WDT_CONTR = 0x35; //设置看门狗,溢出时间是2.2s
	while(1){
		WDT_CONTR = 0x35;
		delayms(1000);
	}
}