#include"header.h"
void adc_init(){
PINSEL1|=0X15400000;
ADCR=0X00200400;
}
int adc_read(unsigned int channel){
unsigned int result=0;
ADCR|=1<<channel;
ADCR|=1<<24;
while(((ADDR>>31)&1)==0);
ADCR^=1<<24;
ADCR^=1<<channel;
result=(ADDR>>6)&0X3FF;
return result;
}

void uart0_integer(int num){
int a[10],i;
if(num==0){
uart0_tx('0');
return;
}
if(num<0){
uart0_tx('-');
num=-num;
}
for(i=0;num;num=num/10,i++){
a[i]=num%10+'0';
}
for(i=i-1;i>=0;i--){
uart0_tx(a[i]);
}
}
