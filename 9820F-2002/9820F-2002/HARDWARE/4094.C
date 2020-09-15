#include "pbdata.h"

u8 _4094_databuff[_4094NUM];

void Out_4094(u8 *buff) //дCD4094�Ӻ���;
{
	u8 i;       //�����Ӻ���;
	u8 j;
	_4094_STBL;       //����Ȼ����״̬����;
	_SPI_SCLKH;
	for(j=0;j<_4094NUM;j++)
	{
		for(i=0;i<8;i++)     //д��λ���ݽ�CD4094;
		{
			if(*(buff+j)&0x80)     //�жϲ�����������;
			{
				_SPI_DINH;      //���ߵ�ƽ;
			}
			else
			{
				_SPI_DINL;      //���͵�ƽ;
			}
			
			_SPI_SCLKL;       //�γ�����������;
			delay_us(5);
			_SPI_SCLKH;
			*(buff+j)<<=1;      //������λ,����һλ����;
			
		}
	}
	_4094_STBH;       //��������;������ʾ;
	delay_us(5);
	_4094_STBL; 
}