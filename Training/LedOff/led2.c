#include<regx51.h>
sbit led1=P2^0;
sbit led2=P2^1;
void delay(){
	int i,j;
	for(i=0;i<1000;i++);
	for(j=0;j<100;j++);
}
void main(){
	while(1){
		led1=0;
		led2=1;
		delay();
		led1=1;
		led2=0;
		delay();
	}
}