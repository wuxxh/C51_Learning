#include <reg52.h>

#define TIMS (65536 - 9216)  //定时器10ms定时,由晶振频率/12

sbit led = P2^0;
int count = 0;

//10ms触发一次
void timer0() interrupt 1
{
	count++;
	if(count >= 100)
	{
		count = 0;
		led = ~led;
	}
	//重新装载,很重要,不然会定时不准
	TL0 = TIMS; //0b0000 0000 ,自动去除高八位
	TH0 = TIMS >> 8; //右移8位
}

void main(){
	//设置定时器0的模式为16位,设置时钟源为系统时钟'
	TMOD = 0x01; //设置GATE为1,打开定时器
	TR0 = 1;
	
	//设置预装载值,是的定时时间是10ms一次
	//10ms触发一次
	TL0 = TIMS; //0b0000 0000 ,自动去除高八位
	TH0 = TIMS >> 8; //右移8位
	
	ET0 = 1; //打开定时器0的中断开关
	EA = 1; //总中断开关
	
	while(1){
		
	}
}