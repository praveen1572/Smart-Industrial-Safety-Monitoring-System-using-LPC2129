#include"header.h"
void uart0_init(unsigned int baud){
unsigned int pclk,result;
if (VPBDIV==0)
pclk=15000000;
if (VPBDIV==1)
pclk=60000000;
if (VPBDIV==2)
pclk=30000000;
result=pclk/(16*baud);
PINSEL0|=0x05;
U0LCR=0X83;
U0DLL=result&0XFF;
U0DLM=(result>>8)&0XFF;
U0LCR=0X3;
}
void uart0_tx(unsigned int data){
U0THR=data;
while(((U0LSR>>5)&1)==0);
}
unsigned int uart0_rx(){
while((U0LSR&1)==0);
return U0RBR;
}
void uart0_tx_string(char * p){
while(*p){
uart0_tx(*p);
p++;
}
}
void uart0_float(float f){
    int n;
    n=(int)f;
    uart0_integer(n);
    uart0_tx('.');
		f=(f-n)*100;
    uart0_integer((int)f);
}
