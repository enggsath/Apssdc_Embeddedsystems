#include<regx51.h>
#define seg P2
sbit c1=P3^0;
sbit c2=P3^1;
sbit c3=P3^2;
sbit r1=P3^3;
sbit r2=P3^4;
sbit r3=P3^5;
sbit r4=P3^6;
//void keypad(unsigned char key1,unsigned char key2,unsigned char key3){
void keypad(key1,key2,key3,key4){
	if(r1==0)
		seg=key1;
	else if(r2==0)
		seg=key2;
	else if(r3==0)
		seg=key3;
	else if(r4==0)
		seg=key4;
}

int main(void){
	while(1){
		c1=0;c2=1;c3=1;
		keypad(0xf9,0x99,0xf8,0x00);
		c1=1;c2=0;c3=1;
		keypad(0xA4,0x92,0x80,0xc0);
		c1=1;c2=1;c3=0;
		keypad(0xb0,0x82,0x90,0x11);
	}
}
