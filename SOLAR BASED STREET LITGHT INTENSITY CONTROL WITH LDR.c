/*
SOLAR BASED STREET LIGHT CONTROL WITH LDR AND IR SENSORS
PIC16F877A 
LDR SENSOR = A0,
IR SENSOR1= A1
IR SENSOR 2 = A2

H POWER LED'S = C2,C1 (PWM)

D2,D3= LED INDICATORS.
*/

#include <16F877A.h>    //Microcontroller Used
#fuses HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
#include "flex_lcd.c"
unsigned long duty=0;

void main()
{
//int duty=512;
   unsigned long ldr,ir1,ir2;
   lcd_init();
 
   setup_port_a( ALL_ANALOG );
   setup_adc(ADC_CLOCK_INTERNAL);
      
 //pwm frequency setup
  setup_timer_2(T2_DIV_BY_16, 127, 1);
    setup_ccp1(CCP_PWM);
    set_pwm1_duty(duty);
   
    setup_ccp2(CCP_PWM);
    set_pwm2_duty(duty);
   
    set_pwm1_duty(duty);
    set_pwm2_duty(duty);
  
  //code initial check up
   output_high(PIN_d2); //green led
   output_high(PIN_d3); //Red Led
   delay_ms(1000);
   output_low(PIN_d2); //mosfet off
   output_low(PIN_d3); //mosfet off
   delay_ms(1000);
   output_high(PIN_d2); //mosfet off
   output_high(PIN_d3); //mosfet off
   delay_ms(1000);
   output_low(PIN_d2); //mosfet off
   output_low(PIN_d3); //mosfet off
   delay_ms(1000);
   
  lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(1,1);
   printf(lcd_putc,"SOLAR POWERED ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"LED-STREET LIGHT");
   delay_ms(2500);
 
     lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(0,1);
   printf(lcd_putc,"WITH AUTO INTENSITY ");
   lcd_gotoxy(4,2);
   printf(lcd_putc,"CONTROL ");
   delay_ms(2500);
 
 
  //infinite loop.......
   while(1)
   {      
    
   //LDR PERCENTAGE.................... 
        set_adc_channel(0);
         delay_ms(10);
         ldr = Read_ADC();   //read ldr adc value
      
       set_adc_channel(1);
         delay_ms(10);
         ir1 = Read_ADC();   //read ldr adc value
      
       set_adc_channel(2);
         delay_ms(10);
         ir2 = Read_ADC();   //read ldr adc value
      
 
 //night mode
 if(ldr>180)
 {
  set_pwm1_duty(15);  set_pwm2_duty(15);  
 //1st sensor activated
 if(ir1>50)
 {
   output_high(pin_d2);
   output_low(pin_d3);
   
   set_pwm1_duty(255); // set the duty cycle
   set_pwm2_duty(15); // set the duty cycle 
   //delay_ms(2000);
  }

 
 //2nd sen else
 
  if(ir2>50)
  {
  output_high(pin_d3);
   output_low(pin_d2);
  set_pwm1_duty(15); // set the duty cycle
  set_pwm2_duty(255); // set the duty cycle 
 }
  
 
 //no vehicle present on road
 if( (ir1<50)&&(ir2<50))
 {
 
   output_low(pin_d2);
   output_low(pin_d3);
    set_pwm1_duty(15);  set_pwm2_duty(15);  
 }
 } //ldr close
 
 else
 {
  set_pwm1_duty(0);  set_pwm2_duty(0);  
  output_low(pin_d2);
   output_low(pin_d3);
 }
 
  }  //whie
}  //main



