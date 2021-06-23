#include<regx51.h>
#define leds P2
#define leds2 P1
void delay(){
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<50;j++);
}
void main(){
	while(1){
		leds=0xff;
		leds2=0x00;
		delay();
		leds=0x00;
		leds2=0xff;
		delay();
		leds=0x0f;
		leds2=0xf0;
		delay();
		leds=0xf0;
		leds2=0x0f;
		delay();
		leds=0x55;
		leds2=0xaa;
		delay();
		leds=0xaa;
		leds2=0x55;
		delay();
	}
}