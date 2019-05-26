/******************************************************************************************
TITLE: INTELLIGENT BREAKING SYSTEM
PIC16F73,

ULTRASONIC 4PIN -- A0,A1
MOTRO DRIVER
LCD -- B PORT
G LED = C4
R LED = C5
C3 = Buzzer.

*******************************************************************************************/
#include <16f73.h>
#fuses HS,PUT,NOWDT,NOPROTECT
#use delay(clock=20000000)
#include "flex_lcd.c"
//int16 distance, time;          // Defining variables 
#define  pin_a0     // Change as you wish, can use any pin in the MCU 
#define ECHO pin_a1     // Change as you wish, can use any pin in the MCU 



   void beep()
{
  output_high(pin_C3);
  delay_ms(700);
  output_low(pin_C3);
  delay_ms(500);
   
}

//VOID MAIN PROGRAMMING......
void main()
{

   setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);     // initiating timer
   
   lcd_init();
   lcd_gotoxy(0,1);
   printf(lcd_putc,"  INTELLIGENT  ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"  BREAKING S/M  ");
   delay_ms(2000);
   
      
   //Microcontroller Health check up
   output_high(pin_C4); //BUZZER
   output_high(pin_C5); //green led
     delay_ms(500);
   output_low(pin_C4);
   output_low(pin_C5);
   delay_ms(500);  beep(); 
   output_high(pin_C4); //BUZZER
   output_high(pin_C5); //green led
     delay_ms(500);
   output_low(pin_C4);
   output_low(pin_C5);
   delay_ms(500);
     //end health check up
 
 lcd_putc('\f');
 
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
  
lcd_gotoxy(1,1);
printf(LCD_PUTC, "\f Distance =%Lucm"distance); // print distance on lcd
delay_ms(500);

//IF OBSTACLE DETECT.......................................
 if(distance<=30)
{
  output_high(pin_C5);
  output_low(pin_C4);
  
  output_low(pin_c6);
  output_low(pin_c7);
  output_low(pin_c1);
  output_low(pin_c2);
  
beep();
//lcd_putc('\f');
lcd_gotoxy(1,2);
printf(lcd_putc,"OBSTACLE ALERT****");
lcd_gotoxy(3,2);
//printf(lcd_putc,"PLS ...STOP");
delay_ms(500);
}
  
else
{
  output_high(pin_C5);
  output_low(pin_C4);
  
  
  output_low(pin_c6);
  output_high(pin_c7);
  output_low(pin_c1);
  output_high(pin_c2);
delay_ms(50);
  
lcd_gotoxy(1,1);
printf(LCD_PUTC, "\f Distance =%Lucm"distance); // print distance on lcd
delay_ms(50);
} 
           
    } //while loop
}  //main loop

