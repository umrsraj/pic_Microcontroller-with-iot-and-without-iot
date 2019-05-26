/*
TITLRE: OBSTACLE ROBOT
PIC16F87A,
A0=  IR-OBSTACLE,
A1=  SWITCH1- SEAT BELT,
C1,C2,C3,D0 = ROBOT WHEELS
B2 TO B7 = LCD,
D1= BUZZER,
D2= GREEN LED,
D3 = RED LED,

 
*/

#include <16F877A.h>
#fuses HS,NOWDT,PROTECT,brownout,put
#use  delay  (clock=20000000) //crystall oscillator 
#include "flex_lcd.c"

#define buzzer pin_d1
#define gled pin_d2
#define rled pin_d3

#define m11 pin_c4
#define m12 pin_c5
#define m21 pin_c6
#define m22 pin_c7

#define pinhigh output_high
#define pinlow output_low

void beep ()
{
pinhigh(buzzer);
delay_ms(1000);
pinlow(buzzer);
delay_ms(10);
}

void main()
{
    
    unsigned int obs = 0;
    
    setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG );
    
   lcd_init();  
  
   lcd_putc('\f');         //Clear LCD 
   lcd_gotoxy(1,1);
   printf(lcd_putc,"  INTELLIGENT  ");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"  BREAKING S/M  ");
   delay_ms(2000);
    
   output_high(PIN_D2);
    output_high(PIN_D3);    
    
    beep ();
    delay_ms(500);   
    output_low(PIN_D2);
    output_low(PIN_D3);    
    
    delay_ms(500);
    
    
    output_high(PIN_D2);
    output_high(PIN_D3);    
   
    delay_ms(500);   
    output_low(PIN_D2);
    output_low(PIN_D3);    
    
     delay_ms(500);    
  output_high(PIN_D2);
    output_high(PIN_D3);    
   
    beep ();
    delay_ms(500);   
    output_low(PIN_D2);
    output_low(PIN_D3);    
  
    
    //delay_ms(2000);
    
   while(true)
   {
                     
      set_adc_channel(0);
      delay_ms(10);// delay built-in function call
      obs = Read_ADC();  
      delay_ms(5);
         
 if (obs>160)
{

delay_ms(100);
pinhigh(rled);
pinlow(gled);

pinlow(m11);
pinlow(m12);
pinlow(m21);
pinlow(m22);
delay_ms(100);

   lcd_putc('\f');         //Clear LCD 
   lcd_gotoxy(1,1);
   printf(lcd_putc," OBSTACLE ALERT ");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"***PLZ CHECK***");
   beep ();
   delay_ms(1000);

}
else 
{
pinhigh(gled);
pinlow(rled);
pinlow(buzzer);


pinhigh(m11);
pinlow(m12);
pinhigh(m21);
pinlow(m22);
delay_ms(100);


 lcd_putc('\f');         //Clear LCD 
   lcd_gotoxy(1,1);
   printf(lcd_putc,"SYSTEM IS NORMAL");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"*****************");
   delay_ms(100);

}

   
   } //WHILE LOOP 
}
    






