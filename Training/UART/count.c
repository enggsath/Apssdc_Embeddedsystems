#include<regx51.h>
#include "uart.h"
sbit button =P1^0;
void main()
{
	unsigned int count=0;
	uart_init();
	while(1)
	{
		if (button==0)
		{
			uart_string("count:");
			count++;
			uart_num(count);
			uart_enter();
		}
		while(button==0);
	}
}
	