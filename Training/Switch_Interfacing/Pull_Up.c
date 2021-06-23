#include<regx51.h>
sbit led=P0^0;
sbit button=P1^0;
void delay(){
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<20;j++);
}
void main(){
	if (button==0){
		led=1;
		delay();
	}
	else{
		led=0;
		delay();
	}
}