/*
AUTOMATIC LDR BASED STREET LIGHT INTENSITY CONTROL WITH VEHICLE PRESENCE 

C2= PWM CHANNEL FOR INTNSITY CONTROL
C4 = G LED ,
C5= R LED,

A1 = IR SENSOR,
A0 = LDR SENSOR,
*/

#include <16F73.h>           //Microcontroller Used
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
   
    
    setup_timer_2(T2_DIV_BY_16, 127, 1);
    setup_ccp1(CCP_PWM);
    set_pwm1_duty(duty);
   
    setup_ccp2(CCP_PWM);
    set_pwm2_duty(duty);
   
    set_pwm1_duty(duty);
    set_pwm2_duty(duty);
    
   output_high(PIN_C4); //green led
   output_high(PIN_C5); //Red Led
   delay_ms(1000);
   output_low(PIN_C4); //mosfet off
   output_low(PIN_C5); //mosfet off
   delay_ms(1000); 
   output_high(PIN_C4); //green led
   output_high(PIN_C5); //Red Led
   delay_ms(1000);
   output_low(PIN_C4); //mosfet off
   output_low(PIN_C5); //mosfet off
   delay_ms(1000);
   
  lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(0,1);
   printf(lcd_putc,"AUTOMATIC STREET ");
   lcd_gotoxy(2,2);
   printf(lcd_putc,"LIGHT INTESITY   ");
   delay_ms(1500);
     lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(3,1);
   printf(lcd_putc,"CONTORL WITH ");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"VEHICLE PRESENCE");
   delay_ms(1500);
 
  
   while(1)
   {      
     
   //LDR PERCENTAGE.................... 
        set_adc_channel(5);
         delay_ms(10);
         ldr = Read_ADC();   //read ldr adc value
      
       set_adc_channel(0);
         delay_ms(10);
         ir1 = Read_ADC();   //read ldr adc value
      
            
       set_adc_channel(1);
         delay_ms(10);
         ir2 = Read_ADC();   //read ldr adc value
 
 
 //night mode
 if(ldr>100){
 output_high(pin_c4);
 
 if(ir1>100)
 {
 
 output_high(pin_C4);
   //output_low(pin_C5);
    
    set_pwm1_duty(255); // set the duty cycle
  //  set_pwm2_duty(255); // set the duty cycle 
  lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(0,1);
   printf(lcd_putc,"STREET LIGHTS= 1");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"INTENSITY = 100 PER ");
   delay_ms(300);
  
 
 }
 
 
 if(ir2>100)
 {
 
// output_high(pin_C4);
   output_high(pin_C5);
    
  //  set_pwm1_duty(255); // set the duty cycle
    set_pwm2_duty(255); // set the duty cycle 
  lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(0,1);
   printf(lcd_putc,"STREET LIGHTS= 2");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"INTENSITY = 100 PER ");
   delay_ms(300);
  
 
 }
 
 
 if((ir1<50))
 {
 //output_low(pin_C4);
 //  output_low(pin_C5);
 //output_high(pin_C2);
 set_pwm1_duty(15); // set the duty cycle
  // set_pwm2_duty(15); // set the duty cycle 
   lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(0,1);
   printf(lcd_putc,"STREET LIGHTS= 1");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"INTENSITY = 50 PER ");
      delay_ms(100);
    
 }
 
 if((ir2<50))
 {
    //output_low(pin_C5);
    //output_high(pin_C1);
  // output_low(pin_C5);
  // set_pwm1_duty(15); // set the duty cycle
   set_pwm2_duty(15); // set the duty cycle 15
   lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(0,1);
   printf(lcd_putc,"STREET LIGHTS= 1");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"INTENSITY = 50 PER ");
   delay_ms(100);
    
 }
 
 
 
 } //ldr close
 
 if(ldr<50)
 {
 
   output_low(pin_C4);
   output_low(pin_C5);
   output_low(pin_c1);
   output_low(pin_c2);
   set_pwm1_duty(0); // set the duty cycle
   set_pwm2_duty(0); // set the duty cycle 
  
   lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(0,1);
   printf(lcd_putc,"STREET LIGHTS= 0");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"AUTO STREET LTS");
   delay_ms(100);
  }
  }  //whie
}  //main



