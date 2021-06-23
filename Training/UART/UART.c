#include<regx51.h>
#include "uart.h"

sbit led=P2^0;
char ch;
void main()
{
	uart_init();
	while(1)
	{
		ch=uart_rx();
		if(ch=='a')
		led=1;
		else
		led=0;
	}
}