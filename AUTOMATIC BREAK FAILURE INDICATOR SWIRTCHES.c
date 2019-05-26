#include <16f877a.h>
#fuses HS,PUT, PROTECT, NOWDT
#use delay(clock=20M)
#include "dc_motor.c"


void main()
{

//HEALTH CHECK UP...............
  output_high(pin_d2);  //
 output_high(pin_d3);   //
 output_high(pin_d1);   //BUZZER ON
 delay_ms(500);
 output_low(pin_d2);   //
 output_low(pin_d3);   //
 output_low(pin_d1);  //BUZZER OFF
 delay_ms(500);
 output_high(pin_d2);  //
 output_high(pin_d3);   //
 output_high(pin_d1);   //BUZZER ON
 delay_ms(500);
 output_low(pin_d2);   //
 output_low(pin_d3);   //
 output_low(pin_d1);  //BUZZER OFF
 delay_ms(500);
 
 output_high(pin_d7);  //relay on



   while(1)
   {
   
//SWITCH ONE PRESSED 
 if(!input(pin_A0))     {

           output_high(PIN_D3); // RED LED ON
           output_low(PIN_d2); //GREEN LED OFF
           output_low(PIN_d7); //BRAEK ON
          beep();delay_ms(2000);
           output_high(PIN_d7); //BREAK RELEASE
}


//SWICH2 PRESSED 
 if(!input(pin_A1))     
 
           output_high(PIN_d1); //BUZ ON
           output_high(PIN_D3); //RED LED 
           output_low(PIN_d2); //G LED OFF
           delay_ms(2000);
           output_low(PIN_d7); //BREAK ON
           output_low(PIN_d1); //BUZ ON
           delay_ms(500);break;
}

   }   //WHILE
} 


