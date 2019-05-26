/*********************************************************************************************************************************************

   Project Title: ARM SECURITY SYSTEM USING METAL DETECTOR AND VIBRATION SENSOR
   MC-PIC16F877A, D2,D3--LED, 
   DTMF decoder--B port(B0 TO B4),
   DC motor DRIVER= C0 TO BELOW, 
   A0-METAL sensor, A1-VIBRATOR sensor,
   B0= BUZZER,
   
***********************************************************************************************************************************************/
#include <16f877a.h>
#fuses HS,PUT, PROTECT, NOWDT
#use delay(clock=20M)
#include "dc_motor.c"

void beep()
{
 output_high(pin_b0);   //BUZZER ON
 delay_ms(500);
 output_low(pin_b0);   //LOW LEVEL LED OFF
 delay_ms(500);
}


void main()
{
 output_high(pin_d2);  //LOW LEVEL LED ON
 output_high(pin_d3);   //HIGH LEVEL LED ON
 beep();
 delay_ms(500);
 output_low(pin_d2);   //LOW LEVEL LED OFF
 output_low(pin_d3);   //HIGH LEVEL LED OFF
 delay_ms(500);
  output_high(pin_d2);  //LOW LEVEL LED ON
 output_high(pin_d3);   //HIGH LEVEL LED ON
 beep();
 delay_ms(500);
 output_low(pin_d2);   //LOW LEVEL LED OFF
 output_low(pin_d3);   //HIGH LEVEL LED OFF
 delay_ms(500);
 

   while(1)
   {
//1ST METAL DETOR SENSOR ACITVATED
 if(input(pin_A0)) 
{
           beep(); beep();
           output_low(PIN_D2); //LED ON
           output_high(PIN_D3); //BUZ ON
           M1_ON(1,0);    //reversing
           delay_ms(700);
           M1_ON(0,0);
          
}

//1ST METAL DETOR SENSOR ACITVATED
else if(!input(pin_A1)) 
{
           beep();
           output_low(PIN_D2); //LED ON
           output_high(PIN_D3); //BUZ ON
           M1_ON(1,0);    //reversing
           delay_ms(700);
           M1_ON(0,0);
          
}

//NORMAL MODE
else
{
        
           output_high(PIN_D2); //LED ON
           output_low(PIN_D3); //BUZ ON
           M1_ON(0,0);    //reversing
           delay_ms(700);
          
          
}
   }   //WHILE
} 


