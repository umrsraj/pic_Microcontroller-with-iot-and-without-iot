/*****************************************************************************
TITLE: WIRLESS GAS AND FIRE DETECTION SYSTEM (RX SECTION) 
TX BOARD
PIC16F877A
PC = A0,A1
D2= RED LED,
D3 = GREEN LED,
PC = A0,A1 WITH MAX232.

********************************************************************************/
#include <16F73.h>        //Microcontroller Used
#fuses   HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
//#use rs232(baud=9600, xmit=PIN_A1, rcv=PIN_A0,stream=PC)  //
//#include "dc_motor.c"

void buzzer()
{
output_high(pin_c3); //buzzer on
delay_ms(700);
output_low(pin_c3); //buzzer off
delay_ms(700);

}



//MAIN PROGRAMMING....................................
void main()
{
      
      output_high(PIN_c3);  //BUZZER ON
   output_high(PIN_c4);  //GREEN LED ON
   output_high(PIN_c5);  //RED LED ON
   delay_ms(1000);
   output_low(PIN_c3);   //BUZZER OFF
   output_low(PIN_c4);
   output_low(PIN_c5);
   delay_ms(1000);
     output_high(PIN_c3);  //BUZZER ON
   output_high(PIN_c4);  //GREEN LED ON
   output_high(PIN_c5);  //RED LED ON
   delay_ms(1000);
   output_low(PIN_c3);   //BUZZER OFF
   output_low(PIN_c4);
   output_low(PIN_c5);
   delay_ms(1000);
   
   output_high (PIN_C4);
   output_low (PIN_C5);
       
       output_high (PIN_A0);
   output_low (PIN_A1);
       
  
       
 //fprintf(PC,"**************************************************************\r\n");delay_ms(200);
// fprintf(PC,"DEVELOPEMENT OF GAS & FIRE LEAKAGE DETECTION \r\n");delay_ms(200);
  //fprintf(PC,"        WITH WIRELESS SENSOR NETWORK\r\n");delay_ms(200);
// fprintf(PC,"**************************************************************\r\n");
  //delay_ms(1000);
     
 
   while(1)
   {
   
   
   
   
 if(input(pin_b0))
  {
      if(input(pin_b1))
      {
      output_low(pin_A0);
      output_low(pin_A1);
      
      buzzer();
      delay_ms(1500);
       output_high(pin_C5);output_low(pin_C4);
     //fprintf(PC,"TEMP HIGH***** PLEASE CHECK******\r\n");
      delay_ms(1500);
            }     
            
      
            
      /*
      if(!input(pin_b2))
      {
       M1_ON(0,0);                          //Forward
       M2_ON(0,0);
      output_high(pin_d3);output_low(pin_d2);
      fprintf(PC,"GAS LEAKAGE ALERT***** PLEASE CHECK******\r\n");
      delay_ms(1000);
          
      }
     
     if(!input(pin_b3))
      { M1_ON(1,0);                          //Forward
       M2_ON(1,0);
       output_high(pin_d2); output_low(pin_d3);   
      fprintf(PC,"SYSTEM IS OK... RUNNNING -----\r\n");
      delay_ms(2000);
       }
     */
     
}  //if rf checks   
 else 
       {
      output_high (pin_A0);
      output_low(pin_A1);
      
       output_high(pin_c4);
       output_low (pin_c5);
       
       }
      
} //while 
                              
} //main

