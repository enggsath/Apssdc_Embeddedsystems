#include<regx51.h>

#define seg1 P2
#define seg2 P3
#define T_lights P1

void Time_delay(unsigned int n){
		unsigned char seg_data[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};//(0,1,2,3,4,5,6,7,8,9)
		int i,j;
		int a,b;
		for(i=n;i>=0;i--)
		{
			seg1=seg_data[i];
			for(j=9;j>=0;j--)
			{
				seg2=seg_data[j];
				for(a=0;a<1000;a++)
				for(b=0;b<50;b++);
			}
		}
}

int main(void){
	P1=0;
	while(1){
		T_lights=0x01;
		Time_delay(2);
		T_lights=0x02;
		Time_delay(1);
		T_lights=0x04;
		Time_delay(0);
	}
}