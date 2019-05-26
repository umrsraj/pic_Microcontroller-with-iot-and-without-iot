
/***************************************************************************
Title: GAS LEAKAGE DETECTOR WITH LCD

A0= MQ2 GAS SENSOR 
C5= GREEN LED,
C4 = RED LED,
LCD=B2 TO B7.
C3 = BUZZER.
********************************************************************************/
#include <16F73.h>  // MC HEADER FILE
#fuses hs,put  //HIGH SPEED, POWER UP TIMER
#use delay(clock=20M)   //CRYSTAL OSCILLATOR   
#include "flex_lcd.c"  //LCD HEADER FILE 


//VOID MAIN PROGRAMMING......
void main()
{
 unsigned int GAS=0;
  
    
   //Microcontroller Health check up
  
   output_high(pin_C4); //GREEN led
   output_high(pin_C5); //RED led
   output_high(pin_C3);//BUZZER ON
   delay_ms(500);
   output_low(pin_C4); //GREEN led
   output_low(pin_C5);
   output_low(pin_C3);//BUZZER ON
   delay_ms(500);
   output_high(pin_C4); //GREEN led
   output_high(pin_C5); //RED led+
   output_high(pin_C3);//BUZZER ON
   delay_ms(500);
   output_low(pin_C4); //GREEN led
   output_low(pin_C5);
   output_low(pin_C3);//BUZZER ON
   delay_ms(500);
   --
    lcd_init();
   
   
     lcd_putc('\f');
   lcd_gotoxy(0,1);
   printf(lcd_putc,"LPG GAS LEAKAGE");
   lcd_gotoxy(1,2);
   printf(lcd_putc," ***DETECTOR****");
   delay_ms(2500);
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(ALL_ANALOG);
 lcd_putc('\f');
 
 
while(1)
{
 set_adc_channel(0); //A0
 delay_ms(1);
 GAS = read_adc();
 delay_ms(1);

/*
lcd_putc('\f');
lcd_gotoxy(1,2);
printf(LCD_PUTC, "PERCENT =%u PER"GAS); // print distance on lcd
delay_ms(1500);
*/
  
 if(GAS > 160)
{
output_low(pin_c5);
output_high(pin_C4);//RED LED ON
output_high(pin_C3);//BUZZER ON

   lcd_putc('\f');
   lcd_gotoxy(3,1);
   printf(lcd_putc,"GAS LEAKAGE ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"***DETECTED*******");
   delay_ms(1500);

lcd_putc('\f');
lcd_gotoxy(1,1);
printf(lcd_putc,"CONTENT OF GAS");
lcd_gotoxy(0,2);
printf(LCD_PUTC, "PERCENT =%u PPM"GAS); // print distance on lcd
delay_ms(1500);
}
  
else
{
output_low(pin_C3);//MOTOR ON
output_high(pin_C5);//LED off
output_low(pin_C4);//LED off

   lcd_putc('\f');
   lcd_gotoxy(0,1);
   printf(lcd_putc,"LPG GAS LEAKAGE");
   lcd_gotoxy(1,2);
   printf(lcd_putc," ***DETECTOR****");
   delay_ms(1500);

lcd_putc('\f');
lcd_gotoxy(1,1);
printf(lcd_putc,"------NORMAL----");
lcd_gotoxy(0,2);
printf(LCD_PUTC, "PERCENT =%u PPM"GAS); // print distance on lcd
delay_ms(1500);

}


} //WHILE LOOP
} //MAIN LOOP


