/*****************************************************************************
TITLE: solar grass cutter
Ao-- ir sensor
C7-- relay
c0,1,2,3 -- robot motors

********************************************************************************/
#include <16F73.h>        //Microcontroller Used
#fuses   HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
//#use rs232(baud=9600, xmit=PIN_A1, rcv=PIN_A0,stream=PC)  //
//#include "dc_motor.c"


/*
void buzzer()
{
output_high(pin_c3); //buzzer on
delay_ms(700);
output_low(pin_c3); //buzzer off
delay_ms(700);

}

*/

//MAIN PROGRAMMING....................................
void main()
{
      
      //output_high(PIN_c3);  //BUZZER ON
   output_high(PIN_c4);  //GREEN LED ON
   output_high(PIN_c5);  //RED LED ON
   delay_ms(1000);
 //  output_low(PIN_c3);   //BUZZER OFF
   output_low(PIN_c4);
   output_low(PIN_c5);
   delay_ms(1000);
 //   output_high(PIN_c3);  //BUZZER ON
   output_high(PIN_c4);  //GREEN LED ON
   output_high(PIN_c5);  //RED LED ON
   delay_ms(1000);
  // output_low(PIN_c3);   //BUZZER OFF
   output_low(PIN_c4);
   output_low(PIN_c5);
   delay_ms(1000);
   
   output_high (PIN_C4);
   output_low (PIN_C5);
            
  
   while(1)
   {
   
   if (input(pin_A0))
   
   {
   output_low(pin_C7);
   
   output_high(pin_C0);
   output_low(pin_C1);
   
   output_low(pin_C2);
   output_high(pin_C3);
   
  // delay_ms(1000);
   
   output_low(pin_C4);
   output_high(pin_C5);
   delay_ms(500);
   
   }
   
   else 
   {
    output_high(pin_C7);
   delay_ms(500);
   output_high(pin_C0);
   output_low(pin_C1);
   
   output_high(pin_C2);
   output_low(pin_C3);
   
   output_high(pin_C4);
   output_low(pin_C5);
   delay_ms(500);
   }
   
 
      
} //while 
                              
} //main

