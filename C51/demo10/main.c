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
        //ÿ�β����жϺ����������´ζ�ʱ����ֵ - 1�������1���ж�
        TH0 = TIMS >> 8;
        TL0 = TIMS;
        //��compareΪ10ʱ�����10ms�ߵ�ƽ��90ms�͵�ƽ
        //��compareΪ60ʱ�����60ms�ߵ�ƽ��40ms�͵�ƽ
        //��compareΪ90ʱ�����90ms�ߵ�ƽ��10ms�͵�ƽ
        speed++;//��ʱ�������ļ���ֵ��1ms��1
        speed%=100;//����speed��0-100��
        if(speed<compare)//����ֵ��Ƚ�ֵ���бȽ�
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
				TMOD = 0x01;      //���ö�ʱ��0Ϊ16λ��ʱ����TH0��TL0ȫ��
        TH0 = TIMS >> 8;  //���ö�ʱ��ֵ��8λ
        TL0 = TIMS;       //���ö�ʱ��ֵ��8λ
        ET0 = 1;  //������ʱ��0�ж�                                          
        EA  = 1;  //����ȫ���ж�                                                      
        TR0 = 1;  //��ʱ��0��ʼ����  
        //��ʼ�������ֹͣ����
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