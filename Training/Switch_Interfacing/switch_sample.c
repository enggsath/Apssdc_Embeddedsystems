#include<regx51.h>
sbit led=P2^0;
sbit sw=P1^0;
void delay(){
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<50;j++);
}
void main(){
	if (sw==0){
		led=1;
		delay();
	}
	else{
	led=0;
	delay();
	}
}