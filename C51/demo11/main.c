#include "reg52.h"
#include <stdio.h>  

sfr WDT_CONTR = 0xe1;

void UartInit(void)                //9600bps@11.0592MHz
{
        PCON &= 0x7F;                //�����ʲ�����
        SCON = 0x50;                //8λ����,�ɱ䲨����
        TMOD &= 0x0F;                //�����ʱ��1ģʽλ
        TMOD |= 0x20;                //�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
        TL1 = 0xFD;                //�趨��ʱ��ֵ
        TH1 = 0xFD;                //�趨��ʱ����װֵ
        ET1 = 0;                //��ֹ��ʱ��1�ж�
        TR1 = 1;                //������ʱ��1
}

/*
**��дprintf���õ�putchar�������ض��򵽴������
**��Ҫ����ͷ�ļ�<stdio.h>
*****/
char putchar(char dat){
        //����ض��򵽴���
        SBUF = dat;     //д�뷢�ͻ���Ĵ���
        while(!TI);    //�ȴ�������ɣ�TI���������־λ ��1
        TI = 0;      //�������־λ����
        return dat;  //���ظ������ĵ�����printf
}
void delayms(unsigned int xms) {
    unsigned int i,j;
    for (i=xms;i>0;i--)
    for(j=110;j>0;j--);
}

void main(){
	UartInit();
	printf("system init\n");
	WDT_CONTR = 0x35; //���ÿ��Ź�,���ʱ����2.2s
	while(1){
		WDT_CONTR = 0x35;
		delayms(1000);
	}
}