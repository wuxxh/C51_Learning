#include "reg52.h"

void send_str(char str[])
{
	int i=0;
	while(str[i] != '\0'){
		SBUF = str[i];
		while(TI == 0);  //TI标识有没有发送完毕,没有发送完毕就等待发送完毕TI=1才能进行下一步
		TI = 0; //每次循环完后TI不会自己置零
		i++; //传下一个字符
	}
}

void main(){
	//配置串口模式为模式1
	SM0 = 0;
	SM1 = 1;
	
	TMOD = 0x20; //设置定时器1工作模式2 8位自动重载
	TR1 = 1;
	TL1 = 0xFD; //设置装载
	TH1 = 0xFD;
	
	PCON = 0;
	
	//SBUF = 0x30;
	send_str("hello_world!");
	while(1){}
}