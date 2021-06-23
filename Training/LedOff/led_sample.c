#include<regx51.h> //header file for 8051 M.C
sbit led=P2^0;//hardware declaration(pin declarations to variables)
void delay();//func declaration
void main(){
	while(1){
		led=0;//func call
		delay();
		led=1;
		delay();
	}
}
void delay(){
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<100;j++);
	}