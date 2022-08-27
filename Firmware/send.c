#include"send.h"
#include"IIC.h"

void send()
{
	unsigned char a[]={'H','e','l','l','o',' ','R','o','b','o','c','o','n'};
	unsigned char i=13,address=0x10;
	unsigned char*byte=a;
	
	while(i--)
	{
		writeByte(address++,*byte++);
	}
	
}
void writeByte(unsigned char address,unsigned char byte)
{
	iic_start();
	iic_write_byte(0x0A);
	iic_wait_ack();
	iic_write_byte(address);
	iic_wait_ack();
	iic_write_byte(byte);
	iic_wait_ack();
	iic_stop();
	Delay_10us(2);
}