/*********************************************************************************************************************************************
RF BASED STEPPER MOTOR CONTROL SYSTEM
   MC-PIC16F73, 
***********************************************************************************************************************************************/
#include <16f73.h>
#fuses HS,PUT,NOWDT,NOPROTECT
#use delay(clock=20000000)


void main(void)
{

          output_high(pin_C2);                 //LED 2 ON 
          output_high(pin_C3);
           delay_ms(1000);
         
           output_low(pin_C2);                 //LED 2 ON 
          output_low(pin_C3);
           delay_ms(1000);
           
           output_high(pin_C2);                 //LED 2 ON 
          output_high(pin_C3);
           delay_ms(1000);
         
           output_low(pin_C2);                 //LED 2 ON 
          output_low(pin_C3);
           delay_ms(1000);
    
   while(1)
   {      
 output_high(pin_A0);
 output_low(pin_A1);    
 output_low(pin_A2);    
 output_low(pin_A3);
 delay_ms(10);
 
 
 output_low(pin_A0);
 output_high(pin_A1);    
 output_low(pin_A2);    
 output_low(pin_A3);
 delay_ms(10);
 
 
 output_low(pin_A0);
 output_low(pin_A1);    
 output_high(pin_A2);    
 output_low(pin_A3);
 delay_ms(10);
 

 output_low(pin_A0);
 output_low(pin_A1);    
 output_low(pin_A2);    
 output_high(pin_A3);
 delay_ms(10);



 
   }
}


