#include<reg52.h>
//#define uchar undigned char
#define uint unsigned int

void setLed(uint num){
	P0=num%0xff;
	P2=num/0xff;
}
void delayUs(unsigned char d){
 	while(--d);
}

void delayMs(unsigned char d){
	while(d--){
		delayUs(248);
		delayUs(248);
	}
}
void main(){
	uint num,d=1;
	P2=0x00;
	P0=0x00;
	while(1){
		for(num=0x01;num<=0x80;num<<=1){
		 	P0=num;
			delayMs(d);
		}
		P0=0x00;
		for(num=0x80;num>0x01;num>>=1){
		 	P2=num;
			delayMs(d);
		}
		P2=0x00;
	}
}
