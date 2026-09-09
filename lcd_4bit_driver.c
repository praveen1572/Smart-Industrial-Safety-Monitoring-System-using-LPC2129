#include"header.h"
void lcd_data(unsigned int data){
	IOCLR1=0XFE<<16;
	IOSET1=(data&0xf0)<<16;
	IOSET1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;

	IOCLR1=0XFE<<16;
	IOSET1=(data&0x0f)<<20;
	IOSET1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;

}
void lcd_cmd(unsigned int cmd){
	IOCLR1=0XFE<<16;
	IOSET1=(cmd&0xf0)<<16;
	IOCLR1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;                                

	IOCLR1=0XFE<<16;
	IOSET1=(cmd&0x0f)<<20;
	IOCLR1=1<<17;
	IOCLR1=1<<18;
	IOSET1=1<<19;
	delay_ms(2);
	IOCLR1=1<<19;
}
void lcd_init(){
//PINSEL0|=0X0;
IODIR1=0XFE<<16;
lcd_cmd(0x28);
lcd_cmd(0x0e);
lcd_cmd(0x01);
}
void lcd_string(char *ptr){
while(*ptr!=0){
lcd_data(*ptr);
ptr++;
}
}

void lcd_integer(int num){
int a[10],i;
if(num==0){
lcd_data('0');
}
if(num<0){
lcd_data('-');
num=-num;
}
for(i=0;num;num=num/10,i++){
a[i]=num%10+'0';
}
for(i=i-1;i>=0;i--){
lcd_data(a[i]);
}
}

void lcd_float(float f){
int num;
if(f==0){
lcd_string("0.0");
}
if(f<0){
lcd_data('-');
f=-f;
}
num=f;
lcd_integer(num);
lcd_data('.');
num=(f-num)*1000000;
lcd_integer(num);

}
void lcd_bin(unsigned int num){
int i;
lcd_cmd(0x80);
for(i=3;i>=0;i--)
lcd_data(((num>>i)&1)+48);
}
void lcd_ascii(unsigned int data){
lcd_cmd(0x80);
lcd_data(data/10+48); 
lcd_data(data%10+48);
}
