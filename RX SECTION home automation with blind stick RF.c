/*****************************************************************************
TITLE: RX SECTION home automation with blind stick RF (RX SECTION) 

PIC16F73
B PORT - RF
C7,C6 - RELAYS
C5 = RED LED,
C4 = GREEN LED,


********************************************************************************/
#include <16F73.h>        //Microcontroller Used
#fuses   HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)  

 unsigned int flag = 0;

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
    
     unsigned int flag = 0;
     
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
   delay_ms(100);
   
  
       
    //   output_high (PIN_b0);
   //output_low (PIN_b1);
       
  
       
 //fprintf(PC,"**************************************************************\r\n");delay_ms(200);
// fprintf(PC,"DEVELOPEMENT OF GAS & FIRE LEAKAGE DETECTION \r\n");delay_ms(200);
  //fprintf(PC,"        WITH WIRELESS SENSOR NETWORK\r\n");delay_ms(200);
// fprintf(PC,"**************************************************************\r\n");
  //delay_ms(1000);
     
 
   while(1)
   {
   
   
   
   
 if(input(pin_b0))
  {
      if(!input(pin_b1))
      {
      output_high(pin_c4);
           
      output_high(pin_c7);
      
      buzzer();
      delay_ms(3000);
         output_low(pin_c4);
         
            }
            
    output_high(pin_c6);
    output_high(pin_c5);
  
}  //if rf checks   
 else 
       {
      output_low(pin_c7);
      output_low(pin_c6);
      
       output_low(pin_c4);
       output_low (pin_c5);
       
       }
      
} //while 
                              
} //main

