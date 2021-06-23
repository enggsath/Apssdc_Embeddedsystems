#include<regx51.h>
#define W_sensor P1
#define Motor P3
void stop_motor();
void run_motor();
void delay(int n)
	{ int i,j;
	for(i=0;i<10000;i++)
	for( j=0;j<n;j++);
}

int main(void){
		while(1)
		{
			if (W_sensor == 0xF0){
				run_motor();
			}
			else if(W_sensor ==0xFF)
			{
				stop_motor();
			}
		}
	}
void run_motor()
{
	Motor =0xA0;
	delay(10);
}
void stop_motor()
{
	Motor = 0x00;
	delay(10);
}