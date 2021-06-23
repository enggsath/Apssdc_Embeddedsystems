#include<regx51.h>
#define seg P3
void delay(){
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<100;j++);
}

void main(){
	while(1){
		seg=0x3f;
		delay();
		seg=0x06;
		delay();
		seg=0x5b;
		delay();
		seg=0x4f;
		delay();
		seg=0x66;
		delay();
		seg=0x6d;
		delay();
		seg=0xfd;
		delay();
		seg=0x07;
		delay();
		seg=0x7f;
		delay();
		seg=0x7f;
		delay();
		seg=0x6f;
		delay();
	}
}