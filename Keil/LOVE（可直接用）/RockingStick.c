#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit vertical_key = P1^0;		   
sbit level_key = P1^1;
unsigned char code text[]={
/*--  文字:  L  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
0x10,0x1F,0x10,0x00,0x00,0x00,0x00,0x00,0x04,0xFC,0x04,0x04,0x04,0x04,0x0C,0x00,

/*--  文字:  O  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
0x07,0x08,0x10,0x10,0x10,0x08,0x07,0x00,0xF0,0x08,0x04,0x04,0x04,0x08,0xF0,0x00,

/*--  文字:  V  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
0x10,0x1E,0x11,0x00,0x00,0x13,0x1C,0x10,0x00,0x00,0xE0,0x1C,0x70,0x80,0x00,0x00,

/*--  文字:  E  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
0x10,0x1F,0x11,0x11,0x17,0x10,0x08,0x00,0x04,0xFC,0x04,0x04,0xC4,0x04,0x18,0x00,


};

void setP0(uchar num){
	uchar i=0,num1=0;
	for(;i<8;i++){
		num1*=2;
		num1+=num%2;
		num/=2;
	}
	P0=num1;
}
void setP2(uchar num){
	P2=num;
}
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
	uchar i,j,le,ver;
	P2=0x00;
	P0=0x00;
	if(level_key)le=1;else le=0;
	if(vertical_key)ver=1;else ver=0;	
	while(1){
		while(1){
		 	if(level_key&&!vertical_key){
			 	delayUs(100);
				if(!level_key)
				break;
			}
		}
		delayMs(50);
		for(i=0;i<sizeof(text)/16;i++)
			for(j=0;j<8;j++){
			 	setP0(text[i*16+j]);
				setP2(text[i*16+j+8]);
				delayMs(2);
			}
	}
}
