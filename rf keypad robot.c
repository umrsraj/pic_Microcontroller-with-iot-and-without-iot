/*///////////////////////////////////////////////////////////////////
TITLE: RX SECTION
ROBOT AT 

RX BOARD
PIC16F877A
RF = B0 TO B4,
L293D = C0 TO GND,
D2,D3,C4,C5 = 4 LED'S
E2= OBSTACLE SENOSOR,
D7,D6,D5,D4,C7 = 5 
//////////////////////////////////////////////////////////////////////
*/
#include <16F73.h>           //Microcontroller Used
#fuses HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)    // operating Clock freequency
//#include "dc_motor.c" 
#define m11 pin_c0
#define m12 pin_c1
#define m21 pin_c2
#define m22 pin_c3


unsigned long duty=0;
void main()
{
    output_high(PIN_C7);
    output_high(PIN_C6);    
    output_high(PIN_C5);
    output_high(PIN_C4);
    delay_ms(500);   
    output_low(PIN_C7);
    output_low(PIN_C6);    
    output_low(PIN_C5);
    output_low(PIN_C4);
    delay_ms(500);
    output_high(PIN_C7);
    output_high(PIN_C6);    
    output_high(PIN_C5);
    output_high(PIN_C4);
    delay_ms(500);   
    output_low(PIN_C7);
    output_low(PIN_C6);    
    output_low(PIN_C5);
    output_low(PIN_C4);
   
    
   
  //APR VOICE MODULE 
 // output_high(PIN_D7); output_high(PIN_D6);  output_high(PIN_D5); output_high(PIN_D4); output_high(PIN_C7);output_high(PIN_C6);
  
  /*
           output_low(PIN_C6); //APR PIN
           delay_ms(150);   
           output_high(PIN_C6); //APR PIN
           delay_ms(1000);
           
    */          
   while(1)
   {      
      //rf data checking................................................
      if(input(pin_B0))
     {
       //  if(!input(pin_e2))
         //{
             if (!(input(pin_B1)))
         {  
         output_high(pin_c4);
		 delay_ms(10);
		 
		 output_high(m11);
		 output_low(m12);
		 output_high(m21);
		 output_low(m22);
		 delay_ms(100);
                   
           
         }
            
         else if (!(input(pin_B2)))
         {  
         output_high(pin_c4);
		 delay_ms(10);
		 
		 output_high(m12);
		 output_low(m11);
		 output_high(m22);
		 output_low(m21);
		 delay_ms(100);
                   
           
         }
      
         
      else  if (!(input(pin_B3)))
         {  
         output_high(pin_c4);
		 delay_ms(10);
		 
		 output_high(m11);
		 output_low(m12);
		 output_high(m21);
		 output_low(m22);
		 delay_ms(100);
                   
           
         }
         
         else if(!(input(pin_B4)))
         {
            output_high(pin_c5);            //LED 4 ON
            output_low(PIN_D4); //APR PIN
           delay_ms(150);   
           output_high(PIN_D4); //APR PIN
           delay_ms(700);
           set_pwm1_duty(duty);
           set_pwm2_duty(duty);
           
            M1_ON(1,0);                          //Backward
            M2_ON(0,1);
            delay_ms(100);
            output_low(PIN_C5);
       

         }
        // } //obstacle
         
        if(input(pin_e2))  //OBSTACLE DETECTED
         {
           // M1_ON(0,1);                          //Backward
            //M2_ON(1,0);
           output_low(PIN_C7); //APR PIN
           delay_ms(150);   
           output_high(PIN_C7); //APR PIN
           delay_ms(500);
          // M1_ON(0,0);                          //Backward
          //  M2_ON(0,0);
         }  
        
     } //IF DATA..................................................................................
        else
         {
           if(input(pin_e2))  //OBSTACLE DETECTED
         {
           output_low(PIN_C7); //APR PIN
           delay_ms(150);   
           output_high(PIN_C7); //APR PIN
           delay_ms(500);
         }
         set_pwm1_duty(0);
          set_pwm2_duty(0);
          output_high(PIN_D7);  output_high(PIN_D6);  output_high(PIN_D5);  output_high(PIN_D4);  output_high(PIN_C7);  output_high(PIN_C6); 
          delay_ms(100);
          }
       
   }  //while 
}


