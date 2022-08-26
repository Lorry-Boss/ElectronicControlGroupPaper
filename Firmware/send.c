#include"send.h"
#include"IIC.h"

void send()
{
	unsigned char i;
	char a[]={'H','e','l','l','o',' ','R','o','b','o','c','o','n'};
	iic_start();
	iic_write_byte(0x0A);
	iic_wait_ack();
	iic_write_byte(0x10);
	iic_wait_ack();
	for(i=0;i<13;i++)
	{
	iic_write_byte(a[i]);
	}
	iic_wait_ack();
	iic_stop();
}