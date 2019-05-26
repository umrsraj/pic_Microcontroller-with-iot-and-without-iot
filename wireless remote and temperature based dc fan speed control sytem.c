/*********************************************************************************************************************************************
remote and temp based dc fan speed control system
   MC-PIC16F73, 
***********************************************************************************************************************************************/
#include <16f73.h>
#fuses HS,PUT,NOWDT,NOPROTECT
#use delay(clock=20000000)
#include "flex_lcd.c"

unsigned int i=0;

void main(void)
{
lcd_init();
lcd_putc('\f');
   lcd_gotoxy(0,1);
   printf(lcd_putc,"  INTELLIGENT  ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"  BREAKING S/M  ");
   delay_ms(1000);

float temp1,temp2;
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG ); 
   
        setup_ccp1(CCP_PWM);
   // set_pwm1_duty(0);
   
  //  setup_ccp2(CCP_PWM);
    //set_pwm2_duty(0);
   
    //setup_timer_2(T2_DIV_BY_16, 255, 1)
     setup_timer_2(T2_DIV_BY_16, 127, 1);
   
    set_pwm1_duty(0);
  //  set_pwm2_duty(0);

          output_high(PIN_c4);  //GREEN LED ON
   output_high(PIN_c5);  //RED LED ON
   delay_ms(1000);
 
   output_low(PIN_c4);
   output_low(PIN_c5);
   delay_ms(1000);

   output_high(PIN_c4);  //GREEN LED ON
   output_high(PIN_c5);  //RED LED ON
   delay_ms(1000);
  
   output_low(PIN_c4);
   output_low(PIN_c5);
   delay_ms(1000);
    
   while(1)
   {      
   
   
   set_adc_channel(0);       //TEMPERATURE ............................                      
      delay_ms(1);
      temp2=read_adc(); 
      delay_ms(1);
      temp1 = (temp2 * 100)/256;
      temp1 = temp1 * 5;
      
 if(input(pin_b0))
 {
 
if (temp1<40)
{
output_high(pin_c4);
output_low(pin_c5);

  output_low(pin_c1);
   //output_high(pin_c2);
   
    set_pwm1_duty(0);
    
lcd_putc('\f');
   lcd_gotoxy(0,1);
   printf(lcd_putc,"fan stoped");
   lcd_gotoxy(1,2);
   printf(lcd_putc," %2.2f",temp1);
   delay_ms(4000);
}


else if (temp1>70)
{
output_high(pin_c4);
output_high(pin_c5);

  output_high(pin_c1);
   //output_high(pin_c2);
   
    set_pwm1_duty(255);
    
lcd_putc('\f');
   lcd_gotoxy(0,1);
   printf(lcd_putc,"HIGH speed");
   lcd_gotoxy(1,2);
   printf(lcd_putc," %2.2f",temp1);
   delay_ms(4000);
   output_low(pin_c1);
}



/////////////////////////////////////////////////////
else if ((temp1>40)||(temp1<70))
{

output_low(pin_c4);
output_high(pin_c5);
lcd_putc('\f');
   lcd_gotoxy(0,1);
   printf(lcd_putc,"normal speed");
   lcd_gotoxy(1,2);
   printf(lcd_putc," %2.2f",temp1);
   

for (i=0;i<20;i++)
{
  output_high(pin_c1);
   //output_high(pin_c2);
   
    set_pwm1_duty(5);
    delay_ms(100);

  //delay_ms(4000);
     output_low(pin_c1);
     delay_ms(400);
}  
   }
  ////////////////////////////////////////////////////////////////////////////// 

 }//rf
 else
 {
 output_low(pin_c4);
 output_low(pin_c5);
 
 output_low(pin_c1);
 
 }



   }//while

}//main



