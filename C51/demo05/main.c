#include "reg52.h"

void send_str(char str[])
{
	int i=0;
	while(str[i] != '\0'){
		SBUF = str[i];
		while(TI == 0);  //TI��ʶ��û�з������,û�з�����Ͼ͵ȴ��������TI=1���ܽ�����һ��
		TI = 0; //ÿ��ѭ�����TI�����Լ�����
		i++; //����һ���ַ�
	}
}

void main(){
	//���ô���ģʽΪģʽ1
	SM0 = 0;
	SM1 = 1;
	
	TMOD = 0x20; //���ö�ʱ��1����ģʽ2 8λ�Զ�����
	TR1 = 1;
	TL1 = 0xFD; //����װ��
	TH1 = 0xFD;
	
	PCON = 0;
	
	//SBUF = 0x30;
	send_str("hello_world!");
	while(1){}
}