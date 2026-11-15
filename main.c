#include"header.h"
//green led p0.14
//yellow led p0.15
//red led p0.16
//pir sensor p0.17
//flame sensor P0.18
//lm35 sensor p0.28 
float temp;
unsigned int a,b,c;
int main(){
	IODIR0|=(1<<14)|(1<<15)|(1<<16);
    adc_init();
    uart0_init(9600);
    lcd_init();
    IOSET0=(1<<14)|(1<<15)|(1<<16);
    while(1){
		lcd_cmd(0x01);
        temp=get_temp();
        a=tempcheck(temp);
        b=pir_check();
        c=flame_check();
        if((a+b+c)==0){
            IOSET0=(1<<15)|(1<<16);
            IOCLR0=(1<<14);
            lcd_cmd(0x80);
            lcd_float(temp);
            lcd_cmd(0xC0);
            lcd_string("SAFE");
        }
        else if((a==1)&&(b==0)&&(c==0)){
            IOSET0=(1<<14)|(1<<16);
            IOCLR0=(1<<15);
            lcd_cmd(0x80);
            lcd_float(temp);
            lcd_cmd(0xC0);
            lcd_string("WARNING");
        }
        else{
            IOSET0=(1<<14)|(1<<15);
            IOCLR0=(1<<16);
            lcd_cmd(0x80);
            lcd_float(temp);
            lcd_cmd(0xC0);
            lcd_string("DANGER");
        }
        uart_print_status();
        delay_sec(3);
    }
}
