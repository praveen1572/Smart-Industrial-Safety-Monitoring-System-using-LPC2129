#include"header.h"
float temp;
unsigned int a,b,c;
int main(){
    IODIR0|=(1<<17)|(1<<18)|(1<<19);
    IODIR0&=~((1<<30)|(1<<5));
    adc_init();
    uart0_init(9600);
    lcd_init();
    while(1){
        temp=get_temp();
        a=tempcheck(temp);
        b=pir_check();
        c=flame_check();
        if((a+b+c)==0){
            IOCLR0=(1<<17);
            IOSET0=(1<<18)|(1<<19);
            lcd_cmd(0x80);
            lcd_float(temp);
            lcd_cmd(0xC0);
            lcd_string("SAFE");
        }
        else if((a==1)&&(b==0)&&(c==0)){
            IOSET0=(1<<17)|(1<<19);
            IOCLR0=(1<<18);
            lcd_cmd(0x80);
            lcd_float(temp);
            lcd_cmd(0xC0);
            lcd_string("WARNING");
        }
        else{
            IOSET0=(1<<17)|(1<<18);
            IOCLR0=(1<<19);
            lcd_cmd(0x80);
            lcd_float(temp);
            lcd_cmd(0xC0);
            lcd_string("DANGER");
        }
        uart_print_status();
        delay_ms(500);
    }
}
