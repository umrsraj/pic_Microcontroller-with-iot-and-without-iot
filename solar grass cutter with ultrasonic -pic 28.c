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
#include "flex_lcd.c"
int16 distance, time;
//int16 distance1, distance2, distance3, distance4, distance5, distance6, distance7;          // Defining variables
#define trig pin_a0     // Change as you wish, can use any pin in the MCU 
#define echo pin_a1     // Change as you wish, can use any pin in the MCU 



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
      
 setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);     // initiating timer


   lcd_init();
   lcd_gotoxy(0,1);
   printf(lcd_putc," ULTRASONIC BSD ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"  GRASS CUTTER  ");
   delay_ms(2000);
   
      
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
   output_high(trig);                         // start the pulse
delay_us(20);                            // sending 20us pulse 
output_low(trig); 
while(!input(ECHO)) {}                  // wait for high state of echo pin and do nothing 

set_timer1(0);                           // setting timer zero 
while(input(ECHO))   {;}                 // Wait for high state of echo pin and do nothing 
time=get_timer1();                       // Getting the time 
distance=time*0.028 + 1.093 ;            // Calculating the distance
  /*
  //////////2nd sample/////////////
  
  output_high(trig);                         // start the pulse
delay_us(20);                            // sending 20us pulse 
output_low(trig); 
while(!input(ECHO)) {}                  // wait for high state of echo pin and do nothing 

set_timer1(0);                           // setting timer zero 
while(input(ECHO))   {;}                 // Wait for high state of echo pin and do nothing 
time=get_timer1();                       // Getting the time 
distance2=time*0.028 + 1.093 ;  
  /////////////3rd sample ///////////////////
  output_high(trig);                         // start the pulse
delay_us(20);                            // sending 20us pulse 
output_low(trig); 
while(!input(ECHO)) {}                  // wait for high state of echo pin and do nothing 

set_timer1(0);                           // setting timer zero 
while(input(ECHO))   {;}                 // Wait for high state of echo pin and do nothing 
time=get_timer1();                       // Getting the time 
distance3=time*0.028 + 1.093 ; 
/////////////4th sample ///////////////////
  output_high(trig);                         // start the pulse
delay_us(20);                            // sending 20us pulse 
output_low(trig); 
while(!input(ECHO)) {}                  // wait for high state of echo pin and do nothing 

set_timer1(0);                           // setting timer zero 
while(input(ECHO))   {;}                 // Wait for high state of echo pin and do nothing 
time=get_timer1();                       // Getting the time 
distance4=time*0.028 + 1.093 ; 
/////////////5th sample ///////////////////
  output_high(trig);                         // start the pulse
delay_us(20);                            // sending 20us pulse 
output_low(trig); 
while(!input(ECHO)) {}                  // wait for high state of echo pin and do nothing 

set_timer1(0);                           // setting timer zero 
while(input(ECHO))   {;}                 // Wait for high state of echo pin and do nothing 
time=get_timer1();                       // Getting the time 
distance5=time*0.028 + 1.093 ; 
/////////////6th sample ///////////////////
  output_high(trig);                         // start the pulse
delay_us(20);                            // sending 20us pulse 
output_low(trig); 
while(!input(ECHO)) {}                  // wait for high state of echo pin and do nothing 

set_timer1(0);                           // setting timer zero 
while(input(ECHO))   {;}                 // Wait for high state of echo pin and do nothing 
time=get_timer1();                       // Getting the time 
distance6=time*0.028 + 1.093 ; 

/////////////7th sample ///////////////////
  output_high(trig);                         // start the pulse
delay_us(20);                            // sending 20us pulse 
output_low(trig); 
while(!input(ECHO)) {}                  // wait for high state of echo pin and do nothing 

set_timer1(0);                           // setting timer zero 
while(input(ECHO))   {;}                 // Wait for high state of echo pin and do nothing 
time=get_timer1();                       // Getting the time 
distance7=time*0.028 + 1.093 ; 


 ///////// average //////////
  distance = (distance1 + distance2 + distance3 + distance4 + distance5 + distance6 + distance7)/7 ;
*/  
lcd_gotoxy(1,1);
printf(LCD_PUTC, "\f Distance =%Lucm"distance); // print distance on lcd
delay_ms(500);

   
   if (distance <40)
   
   {
   output_low((PIN_C6));
   
   output_high(pin_C0);
   output_low(pin_C1);
   
   output_low(pin_C2);
   output_high(pin_C3);
   
  delay_ms(100);
   
   output_low(pin_C4);
   output_high(pin_C5);
   delay_ms(2000);
   
   }
   
   else 
   {
      output_high((PIN_C6));
   delay_ms(100);
   output_high(pin_C0);
   output_low(pin_C1);
   
   output_high(pin_C2);
   output_low(pin_C3);
   
   output_high(pin_C4);
   output_low(pin_C5);
   delay_ms(100);
  
   }
   
 
      
} //while 
                              
} //main

