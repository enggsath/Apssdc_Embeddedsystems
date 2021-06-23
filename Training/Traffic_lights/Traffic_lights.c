#include<regx51.h>
#define T_lights P2
void delay(){
	int i,j;
	for(i=0;i<1000;i++);
}
int main(void){
	while(1){
	T_lights=0x01;
	delay();
	T_lights=0x02;
	delay();
	T_lights=0x04;
	delay();
	}
}