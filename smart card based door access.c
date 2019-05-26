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
#include <16f72.h>
#fuses HS,PUT,NOWDT,NOPROTECT
#use delay(clock=20000000)
#include "flex_lcd.c"
//int16 distance, time;          // Defining variables 



   void beep()
{
  output_high(pin_C3);
  delay_ms(400);
  output_low(pin_C3);
  delay_ms(100);
   
}

//VOID MAIN PROGRAMMING......
void main()
{
   
   lcd_init();
    lcd_putc('\f');
   lcd_gotoxy(0,1);
   printf(lcd_putc,"SMART CARD BASED");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"  DOOR ACCESS   ");
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
   beep(); 
     //end health check up
 

 
 while(1)
{
if (input(pin_A0))
{
 output_low(pin_c5);
 lcd_putc('\f');
   lcd_gotoxy(0,1);
   printf(lcd_putc,"   SMART CARD   ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"*** INSERTED ***");
   output_high(pin_c7);
   output_high(pin_c4);
beep ();
beep ();
delay_ms(1000);
while (input(pin_A0));
lcd_putc('\f');
   lcd_gotoxy(0,1);
   printf(lcd_putc,"   SMART CARD   ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"*** REMOVED  ***");
   output_low(pin_c7);
   output_low(pin_c4);
beep ();
beep ();
}
else
{
 lcd_putc('\f');
   lcd_gotoxy(0,1);
   printf(lcd_putc,"PLEASE INSERT UR");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"   SMART CARD   ");
//beep ();
output_low(pin_c4);
   output_high(pin_c5);
delay_ms(300);
}
    } //while loop
}  //main loop

