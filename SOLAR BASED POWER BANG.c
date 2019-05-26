/******************************************************************************************
TITLE:SOLAR POWER BASED POWER BANK
PIC16F73,
BATTERY INPUT REF= A0,
LCD= B PORT(B2 TO B7)
C4= GREEN LED,
C5= RED LED.
C3= BUZZER,
*******************************************************************************************/
#include <16F73.h>   //MC NAME
#fuses HS,NOWDT,PROTECT,put
#use delay(clock=20M) //CRYSTAL OSCILLATOR
#include <flex_lcd.c> //LCD IN

//BUZZER SUBROUTINE
void beep()
{
output_high(pin_c3); //BUZZER ON
delay_ms(500); //MILLI SECONDS
output_low(pin_c3); //BUZ OFF
 delay_ms(500);
}

//MAIN----------------------------------------------------
void main() 
{

//unsigned int temp;
   float battery;  // battery input reading variables

      lcd_init(); //INITIALIZE LCD
   //internal anolog acitvation........
   setup_adc(ADC_CLOCK_INTERNAL); //internal clock usage
   setup_adc_ports( ALL_ANALOG ); // all anolog

//check up
output_high(pin_c4);  //greeen on
output_high(pin_c5);  //red on
   delay_ms(1000);
output_low(pin_c4); //g off 
output_low(pin_c5); // r off
 delay_ms(1000);beep();
 
output_high(pin_c4);
output_high(pin_c5);
   delay_ms(1000);
output_low(pin_c4);
output_low(pin_c5);
 delay_ms(1000);

           
     
  //display initial messsage ....................................
              printf(lcd_putc,"\f"); //LCD CLEAR 
              lcd_gotoxy(2,1); //C,R
              printf(lcd_putc,"SOLAR BASED ");
              lcd_gotoxy(3,2);
              printf(lcd_putc,"POWER BANK ");
              delay_ms(2000);
              
                         
  
  
  //infity loop........................................
    while(TRUE)
    {
       set_adc_channel(0);
      delay_ms(50);// delay built-in function call
      battery = Read_ADC();                   // A/D read functions- built-in         
      battery=battery*123/1023;
         //  battery=battery*5.0*10/1023; 
         
         
      /*
      lcd_putc("\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"voltage:%f ",battery);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"pizeo:%f volts ",pizeo);
      delay_ms(5000);
      */


 
      //LOW VOLTAGE 
        if(battery<8)
        {
         beep();
            output_low(pin_C4);  //G OFF
           output_high(pin_C5);  //R ON
           output_low(pin_C7); output_low(pin_C6);
           
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"LOW B VOLTAGE ALERT***  ");
               lcd_gotoxy(0,2);
            printf(lcd_putc,"B VOLT = %f V",battery);
              delay_ms(1000);
               
        }
        
      //HIGHT VOLTAGE 
        if(battery>15)
        {
           beep();beep();
           output_low(pin_C4);  //G OFF
           output_high(pin_C5);  //R ON
           output_low(pin_C7); output_low(pin_C6);
           
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
            printf(lcd_putc,"HIGH B VOLTAGE ALERT***  ");
            lcd_gotoxy(0,2);
           printf(lcd_putc,"B VOLT = %f V",battery);
            delay_ms(1000);
          
 }
      
//if battery is healthy

  if((battery>8)&&(battery<15))   
  {
     
           output_high(pin_C4);  //G OFF
           output_low(pin_C5);  //R Off
           output_high(pin_C7);output_high(pin_C6);
               printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
             printf(lcd_putc,"PWR BANG CONNECTED");
               lcd_gotoxy(0,2);
             printf(lcd_putc,"B VOLT = %f V",battery);
              delay_ms(1000);
  
  }
     
   
    } //while loop
}  //main loop






