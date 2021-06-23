#include<regx51.h>
#include "lcd.h"
void main(){
	lcd_init();
	while(1)
	{
	lcd_cmd(0x80);
	lcd_string("Welcome to");
	lcd_cmd(0xc5);
	lcd_string("APSSDC");
	}
}