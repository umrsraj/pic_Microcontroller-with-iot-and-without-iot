/*********************************************************************************************************************************************
TITLE 
PIC16F77
C3= ZERO CROSSING DETECTOR,
LCD= B PORT,
C4= GREEN LED,
C5 = RED LED,

C2= PWM WITH RELAY

***********************************************************************************************************************************************/
#include <16f877A.h>
#fuses HS,PUT,NOWDT,NOPROTECT
#use delay(clock=20000000)
unsigned long duty = 0;
int i=0;
void main(void)
{
   //PWM CHANNEL PROGRAMMING
   duty = 0;
 setup_timer_2(T2_DIV_BY_16, 127, 1);
 
   setup_ccp1(CCP_PWM); //c2   setup_ccp2(CCP_PWM); //c1
   set_pwm1_duty(duty);
   
          output_high(pin_D2);                 //LED 2 ON 
          output_high(pin_D3);                 //LED 2 ON
          delay_ms(1000);
           output_low(pin_D2);                 //LED 2 ON 
          output_low(pin_D3);                 //LED 2 ON
           delay_ms(1000);
           delay_ms(3000);
    
while(1)
{      
             set_pwm1_duty(0);
             set_pwm2_duty(0);
  //zero crossing detector checking ,,,,,,
if(!input(pin_a0))  
{              
           output_low(PIN_D2); output_high(PIN_D3);  //
           set_pwm1_duty(0);
           set_pwm2_duty(0);
           
           for(i=0;i<100;i++)
           { 
             set_pwm1_duty(255);set_pwm2_duty(255);
             output_low(pin_C1); output_low(pin_C2); 
              delay_ms(3);
             output_high(pin_c1);  output_high(pin_c2);
             set_pwm1_duty(0);set_pwm2_duty(0);
              delay_ms(17);  //15
           }
            
while(1)
{            
         
           set_pwm1_duty(255);
           output_low(PIN_D3); output_high(PIN_D2);
         
  }
         
}     
      
         
   } //WHILE LOOP1
}  //MAIN LOOP
         




