#include "header.h"
float get_temp(void){
    unsigned int adc_val;
    float voltage;
    adc_val=adc_read(1);
    voltage=(adc_val*3.3)/1023.0;
    return voltage/0.01;
}

unsigned int tempcheck(float temp){
    if(temp<35)
        return 0;
    else if(temp<=40)
        return 1;
    else
        return 2;
}

unsigned int pir_check(void){
    if(IOPIN0&(1<<30))
        return 1;
    return 0;
}

unsigned int flame_check(void){
    if(IOPIN0&(1<<5))
        return 0;
    return 1;
}

void uart_print_status(void){
    uart0_tx_string("Temperature:");
    uart0_float(temp);
    uart0_tx_string("\r\n");
    uart0_tx_string("PIR:");
    uart0_integer(b);
    uart0_tx_string("\r\n");
    uart0_tx_string("Flame:");
    uart0_integer(c);
    uart0_tx_string("\r\n");
    uart0_tx_string("Machine Status:");
    if((a+b+c)==0)
        uart0_tx_string("SAFE");
    else if((a==1)&&(b==0)&&(c==0))
        uart0_tx_string("WARNING");
    else
        uart0_tx_string("DANGER");
    uart0_tx_string("\r\n");
    uart0_tx_string("LED:");
    if((a+b+c)==0)
        uart0_tx_string("GREEN");
    else if((a==1)&&(b==0)&&(c==0))
        uart0_tx_string("YELLOW");
    else
        uart0_tx_string("RED");
    uart0_tx_string("\r\n\r\n");
}
