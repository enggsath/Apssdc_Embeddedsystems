#include<regx51.h>
#define led P2

void delay(){
	int i,j;
	for(i=0;i<100;i++)
	for(j=0;j<50;j++);
}

void main(){
	int x=0x00;
	while(1){
		for(x=0x01;x<=0x80;x=x<<1){
			led=x;
			delay();
		}
		for(x=0x80;x>=0x01;x=x>>1){
			led=x;
			delay();
		}
	}
}