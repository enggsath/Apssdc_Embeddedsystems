#include<regx51.h>
#include "lcd.h"
#define W_sensor P1
sbit in1=P3^5;
sbit in2=P3^6;
void stop_motor()
{
	in1=0;
	in2=0;
	lcd_cmd(0xcc);
	lcd_string("OF");
}
void run_motor()
{
	in1=0;
	in2=1;
	lcd_cmd(0xcc);
	lcd_string("ON");
}
void level(unsigned char dat){
	int i;
	unsigned char W_level[5]={0xF0,0xFC,0xFE,0xFF};
	for(i=0;i<4;i++)
	{
		if(W_level[i]==dat)
		{
			lcd_cmd(0x8c);
			lcd_data(i);
		}
	}
}
void main()
{
	lcd_init();
	lcd_cmd(0x80); //start at 1st row and 1st colmn
	lcd_string("Automatic Water");
	lcd_cmd(0xc0); //start at 2ndrow and 1st colmn
	lcd_string("Level Controller");
	lcd_init();
	while(1)
	{
		lcd_cmd(0x80);
		lcd_string("WaterLevel:  ");
		lcd_cmd(0xc0);
		lcd_string("MotorStatus:  ");
		
		level(W_sensor);
		
		if(W_sensor ==0xf0)
		{	run_motor(); }
		else if(W_sensor == 0xff)
		{	stop_motor(); }
		
	}
}
